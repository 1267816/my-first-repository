# ai-workspace
- 本文件夹专门给ai提供，用作工作区。
- `update_repo_stats.py`：重新生成各 README 里的统计区块（标记为 `AUTO-STATS` 的部分）。用法见脚本开头的说明；平时不用手动跑，提交前的勾子会自动执行。
- `git-hooks/pre-commit`：提交前自动跑上面那个脚本的勾子。它和脚本一起放在本目录里，不往仓库其他目录写文件。
- 勾子靠仓库配置 `core.hooksPath=ai-workspace/git-hooks` 生效。换电脑或重新克隆后执行一次 `python ai-workspace/update_repo_stats.py --install-hook` 即可恢复（该设置只改本地 `.git/config`）。
