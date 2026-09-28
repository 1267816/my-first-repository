#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""重新生成 README 里的统计区块，省掉手动维护数字的麻烦。

本脚本属于 ai-workspace，生成的文件和勾子也都放在 ai-workspace 里，
它只会更新 README 中被标记包住的那几段内容，其余文字一律不动。

用法（在仓库里任意位置执行都可以，脚本自己会找仓库根目录）：

    python ai-workspace/update_repo_stats.py                  更新统计区块
    python ai-workspace/update_repo_stats.py --check          只检查是否需要更新，不改文件
    python ai-workspace/update_repo_stats.py --install-hook   把 ai-workspace/git-hooks 设为勾子目录
    python ai-workspace/update_repo_stats.py --uninstall-hook 取消勾子目录设置

统计区块用下面两行包起来，名字相同的区块内容一致，可以出现在多个 README 里：

    <!-- BEGIN AUTO-STATS:overview -->
    ...
    <!-- END AUTO-STATS:overview -->

目前支持的名字：overview / c-learning / front-end / markdown。
需要人工写的内容（说明文字、目录结构、命名约定、鸣谢等）都放在标记外面，不受影响。
只依赖 Python 标准库，不需要额外安装包。
"""

from __future__ import annotations

import os
import re
import subprocess
import sys
from datetime import date
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]

MARKER = re.compile(
    r"<!-- BEGIN AUTO-STATS:(?P<name>[a-z-]+) -->"
    r"(?P<body>.*?)"
    r"<!-- END AUTO-STATS:(?P=name) -->",
    re.S,
)

SKIP_DIRS = {".git", "node_modules", "__pycache__"}

def count_files(directory: Path, pattern: str) -> int:
    if not directory.is_dir():
        return 0
    return sum(1 for _ in directory.rglob(pattern))


def week_sort_key(path: Path) -> tuple[int, str]:
    """按目录名里的 weekN 排序；认不出编号的排在最后。"""
    matched = re.match(r"^week(\d+)", path.name)
    return (int(matched.group(1)) if matched else 999, path.name)


def c_learning_dirs() -> list[Path]:
    """扫描 C-Learning 下的周目录，所以目录改名不用改脚本。"""
    root = REPO / "C-Learning"
    if not root.is_dir():
        return []
    return sorted((p for p in root.iterdir() if p.is_dir()), key=week_sort_key)


def c_learning_notes() -> int:
    return sum(count_files(week / "note", "*.md") for week in c_learning_dirs())


def markdown_notes() -> list[str]:
    return sorted(
        p.name
        for p in (REPO / "Markdown-learning").glob("*.md")
        if p.name.lower() != "readme.md"
    )


def overview_block() -> str:
    c_files = count_files(REPO / "C-Learning", "*.c")
    pdfs = count_files(REPO / "C-Learning", "*.pdf")
    htmls = count_files(REPO / "front-end-practice", "*.html")
    notes = len(markdown_notes())
    return (
        f"仓库统计（自动生成于 {date.today().isoformat()}）："
        f"C 语言练习 {c_files} 个 `.c` 文件 · 课程课件 {pdfs} 份 · "
        f"C 语言笔记 {c_learning_notes()} 篇 · "
        f"前端练习 {htmls} 个 HTML · Markdown 笔记 {notes} 份。"
    )


def c_learning_block() -> str:
    def cell(number: int) -> str:
        return str(number) if number else "—"

    lines = [
        "| 周目录 | `.c` 文件 | 课件 | 笔记 |",
        "| --- | --- | --- | --- |",
    ]
    for week_dir in c_learning_dirs():
        lines.append(
            "| {name} | {c} | {pdf} | {note} |".format(
                name=week_dir.name,
                c=cell(count_files(week_dir, "*.c")),
                pdf=cell(count_files(week_dir / "docs", "*.pdf")),
                note=cell(count_files(week_dir / "note", "*.md")),
            )
        )
    return "\n".join(lines)


def front_end_block() -> str:
    html_dir = REPO / "front-end-practice"
    numbered: list[tuple[int, str]] = []
    others: list[str] = []
    for path in sorted(html_dir.glob("*.html")):
        matched = re.match(r"^(\d+)\.", path.name)
        if matched:
            numbered.append((int(matched.group(1)), path.name))
        else:
            others.append(path.name)
    numbered.sort()
    css = sorted(p.name for p in (html_dir / "css").glob("*.css"))
    js = sorted(p.name for p in (html_dir / "js").glob("*.js"))

    first_line = f"当前共 {len(numbered) + len(others)} 个 HTML 练习文件。"
    if numbered:
        first_line += (
            f"编号 {numbered[0][0]}–{numbered[-1][0]} 按学习顺序排列"
            f"（`{numbered[0][1]}` … `{numbered[-1][1]}`）。"
        )
    if others:
        first_line += "另有 " + "、".join(f"`{name}`" for name in others) + "。"

    lines = [first_line]
    if css or js:
        lines.append(
            f"配套文件：`css/` 下 {len(css)} 个样式表，`js/` 下 {len(js)} 个脚本。"
        )
    return "\n".join(lines)


def markdown_block() -> str:
    notes = markdown_notes()
    images = sorted(
        p.name
        for p in (REPO / "Markdown-learning").iterdir()
        if p.suffix.lower() in {".png", ".jpg", ".jpeg", ".gif"}
    )
    if notes:
        line = "笔记文件：" + "、".join(f"`{name}`" for name in notes) + "。"
    else:
        line = "笔记文件：暂无。"
    if images:
        line += "配图：" + "、".join(f"`{name}`" for name in images) + "。"
    return line


BLOCKS = {
    "overview": overview_block,
    "c-learning": c_learning_block,
    "front-end": front_end_block,
    "markdown": markdown_block,
}


def markdown_files() -> list[Path]:
    found: list[Path] = []
    for path in REPO.rglob("*.md"):
        if any(part in SKIP_DIRS for part in path.parts):
            continue
        found.append(path)
    return sorted(found)


def update_file(path: Path, check_only: bool) -> list[str]:
    """返回本次发生变化的区块名字列表。"""
    raw = path.read_bytes()
    uses_crlf = b"\r\n" in raw
    text = raw.decode("utf-8").replace("\r\n", "\n")
    changed: list[str] = []

    def replace(matched: re.Match[str]) -> str:
        name = matched.group("name")
        if name not in BLOCKS:
            print(f"  [忽略] 未知的区块名：{name}")
            return matched.group(0)
        body = "\n" + BLOCKS[name]().strip("\n") + "\n"
        if matched.group("body") != body:
            changed.append(name)
        return (
            f"<!-- BEGIN AUTO-STATS:{name} -->{body}<!-- END AUTO-STATS:{name} -->"
        )

    new_text = MARKER.sub(replace, text)
    if not changed:
        return []

    if not check_only:
        output = new_text.replace("\n", "\r\n") if uses_crlf else new_text
        path.write_bytes(output.encode("utf-8"))
    return changed


HOOK_DIR_REL = "ai-workspace/git-hooks"
HOOK_PATH = REPO / HOOK_DIR_REL / "pre-commit"
LEGACY_HOOK = REPO / ".git" / "hooks" / "pre-commit"
HOOK_MARK = "由 ai-workspace/update_repo_stats.py 生成"
HOOK_BODY = f"""#!/bin/sh
# {HOOK_MARK}
# 提交前重新生成 README 里的统计区块，并把它们加入本次提交。
root="$(git rev-parse --show-toplevel)" || exit 0
if command -v python >/dev/null 2>&1; then
  py=python
elif command -v py >/dev/null 2>&1; then
  py=py
else
  exit 0
fi
"$py" "$root/ai-workspace/update_repo_stats.py" >/dev/null 2>&1 || exit 0
git -C "$root" add README.md C-Learning/README.md front-end-practice/README.md Markdown-learning/README.md 2>/dev/null
exit 0
"""


def git(*args: str) -> subprocess.CompletedProcess[str]:
    return subprocess.run(
        ["git", *args], cwd=REPO, capture_output=True, text=True, check=False
    )


def install_hook() -> None:
    if not (REPO / ".git").is_dir():
        print("这里不是 git 仓库，跳过勾子安装")
        return
    HOOK_PATH.parent.mkdir(parents=True, exist_ok=True)
    HOOK_PATH.write_bytes(HOOK_BODY.encode("utf-8"))
    os.chmod(HOOK_PATH, 0o755)
    git("config", "core.hooksPath", HOOK_DIR_REL)
    print(f"勾子文件：{HOOK_PATH.relative_to(REPO)}")
    print(f"已设置 core.hooksPath = {HOOK_DIR_REL}（勾子目录仍在仓库内）")
    if LEGACY_HOOK.is_file():
        content = LEGACY_HOOK.read_text(encoding="utf-8", errors="ignore")
        if "由 ai-workspace" in content:
            LEGACY_HOOK.unlink()
            print("已删除先前放在 .git/hooks 下的同名勾子")


def uninstall_hook() -> None:
    current = git("config", "--get", "core.hooksPath").stdout.strip()
    if current:
        git("config", "--unset", "core.hooksPath")
        print(f"已取消 core.hooksPath 设置（原值：{current}）")
    else:
        print("core.hooksPath 未设置，无需处理")
    print(f"勾子文件仍保留在 {HOOK_PATH.relative_to(REPO)}，需要时重新执行 --install-hook")


def main() -> int:
    args = sys.argv[1:]
    if "--install-hook" in args:
        install_hook()
        return 0
    if "--uninstall-hook" in args:
        uninstall_hook()
        return 0

    check_only = "--check" in args
    any_changed = False
    for path in markdown_files():
        changed = update_file(path, check_only)
        if changed:
            any_changed = True
            relative = path.relative_to(REPO)
            print(f"[{'需要更新' if check_only else '已更新'}] {relative}：{'、'.join(changed)}")

    if not any_changed:
        print("所有统计区块都是最新的")
    elif check_only:
        print("运行不带 --check 的命令即可更新。")
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
