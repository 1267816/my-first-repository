# No.12｜C. 小猪玩音游

| 项 | 内容 |
| --- | --- |
| 题源 | 【华为杯】2026 年广东工业大学月赛（同步赛），牛客 |
| 通过情况 | 439 人通过（1245 人报名） |
| 做题日期 | 2026-10-18 |
| 结果 | 提交3次，第3次答案正确 |

## 题目

### 题目描述

小猪最近入坑了一个叫「吃你字母」的音乐游戏，每天两眼一睁就是出勤。每次下勤小猪都想看看自己的成绩，但是服务器太烂了，总是卡住查不到分，于是，小猪写了个程序决定算一算自己的 Rating。

游戏中共有 N 首歌曲，编号为 1 到 N。第 i 首歌曲有一个固定的定数 d_i，定数为恰好保留两位小数的实数。通过爬取服务器记录，查询到小猪一共进行了 M 次游玩，每次游玩记录包含歌曲编号和本次游玩的准确率（ACC）。

本题规定单次游玩的准确率（ACC）的输入范围为 0.00% 到 100.90%。

请注意，本题要求与现实音游中可能采用的定数计算方式不同，请按照题面计算。

对于一次定数为 d，准确率为 a% 的一次游玩，其单曲评分定义如下：

- 当 a < 97.50 时，单曲评分为 0；
- 当 97.50 ≤ a ≤ 100.90 时，单曲评分在 d 和 d + 2.15 之间随准确率线性增长。也就是说，a = 97.50 时单曲评分为 d，a = 100.90 时单曲评分为 d + 2.15。

因此，一次游玩等效的单曲评分为：

```text
S(d, a) = 0                                          (0 ≤ a < 97.50)
        = d + 2.15 × (a - 97.50) / (100.90 - 97.50)  (97.50 ≤ a ≤ 100.90)
```

计算 Rating 时，我们将所有歌曲的最高单曲评分从高到低排序，取前 30 个位置组成 B30（best 30th），作为计算分数的依据。

小猪可能多次游玩同一首歌曲。对于每首歌曲，只保留该歌曲所有游玩记录中的最高单曲评分；同一首歌曲最多只能在 B30 中出现一次。

没有游玩过的歌曲，以及不足 30 首歌曲时多出来的位置，都视为 0 分。小猪的 Rating 定义为 B30 中 30 个分数的平均值：

```text
Rating = (B30 中 30 个分数之和) / 30
```

例如，小猪只游玩过一首歌曲，且这首歌的最高单曲评分为 15.90，那么 Rating 是 15.90 / 30 = 0.53。

现在给出所有歌曲的定数和小猪的全部游玩记录，请你计算他的 Rating。

### 输入描述

- 第一行包含两个整数 N, M (1 ≤ N, M ≤ 2 × 10⁵)，分别表示歌曲数量和游玩记录数量。
- 第二行包含 N 个实数 d_1, d_2, …, d_N (1.00 ≤ d_i ≤ 20.00)，表示每首歌曲的定数。
- 接下来 M 行，每行包含一个整数 s_j (1 ≤ s_j ≤ N) 和一个实数 a_j (0.00 ≤ a_j ≤ 100.90)，表示第 j 次游玩的是第 s_j 首歌曲，准确率（ACC）为 a_j%。输入中的定数和 ACC 均恰好包含两位小数，且不带百分号。
- 保证至少有一条游玩记录。

### 输出描述

输出一个浮点数，表示小猪的 Rating。

如果你的答案与正确答案的绝对误差或相对误差不超过 10⁻⁶，你的答案将被视为正确。

### 示例 1

**输入**
```text
3 6
15.90 12.00 14.00
1 97.50
1 100.90
2 99.20
2 98.18
3 97.49
1 99.20
```

**输出**
```text
1.0375000000
```

**说明**
样例中，第 1 首歌曲的最高分来自 100.90%，为 15.90 + 2.15 = 18.05；第 2 首歌曲在 99.20% 时的得分为 12.00 + 2.15 × (99.20 − 97.50) / (100.90 − 97.50) = 13.075；第 3 首歌曲的 ACC 低于 97.50%，得分为 0。因此 B30 的分数和为 31.125，其余 27 个位置补 0，Rating 为 31.125 / 30 = 1.0375。

## 提交记录

### 提交1

```c
#include <stdio.h>

int main(void) {
    int N,M;
    scanf("%d %d",&N,&M);

    double d[N];
    int i;
    for (i=0;i<N;i++) {
        scanf("%lf",&d[i]);
    }

    int song;
    double rate[N];
    for (i=0;i<N;i++) {
        rate[i]=0.00;
    }
    double acc;
    double rating;
    for (i=0;i<M;i++) {
        scanf("%d %lf",&song,&acc);
        if (acc<97.50) {
            rating=0;
        } else {
            rating=d[song-1]+2.15*((acc-97.50)/(100.90-97.50));
        }
        if (rating>rate[song-1]) {
            rate[song-1]=rating;
        }
    }

    double b[30];
    for (i=0;i<30;i++) {
        b[i]=0.00;
    }
    int j;
    for (i=0;i<N;i++) {
        for (j=0;j<30;j++) {
            if (rate[i]>b[j]) {
                b[j]=rate[i];
                break;
            }
        }
    }

    double finalrating=0;
    for (i=0;i<30;i++) {
        finalrating+=b[i];
    }
    finalrating/=30;
    printf("%.10f\n",finalrating);

    return 0;
}
```

判题结果：答案错误

### 提交2

```c
#include <stdio.h>
const double eps=1e-8;

int main(void) {
    int N,M;
    scanf("%d %d",&N,&M);

    double d[N];
    int i;
    for (i=0;i<N;i++) {
        scanf("%lf",&d[i]);
    }

    int song;
    double rate[N];
    for (i=0;i<N;i++) {
        rate[i]=0.00;
    }
    double acc;
    double rating;
    for (i=0;i<M;i++) {
        scanf("%d %lf",&song,&acc);
        if (97.50-acc<eps) {
            rating=0;
        } else {
            rating=d[song-1]+2.15*((acc-97.50)/(100.90-97.50));
        }
        if (rating-rate[song-1]>eps) {
            rate[song-1]=rating;
        }
    }

    double b[30];
    for (i=0;i<30;i++) {
        b[i]=0.00;
    }
    int j;
    for (i=0;i<N;i++) {
        for (j=0;j<30;j++) {
            if (rate[i]-b[j]>eps) {
                b[j]=rate[i];
                break;
            }
        }
    }

    double finalrating=0;
    for (i=0;i<30;i++) {
        finalrating+=b[i];
    }
    finalrating/=30;
    printf("%.10f\n",finalrating);

    return 0;
}
```

判题结果：答案错误

### 提交3

```c
#include <stdio.h>
const double eps=1e-9;

int main(void) {
    // 第一行: N为歌曲数量，不大于200000
    // 第二行: M为游玩记录数量，不大于200000
    // 第三行: N个实数d_1, d_2, ..., d_N表示每首歌曲定数，不小于1.00不大于20.00
    // 接下来M行: s_i 表示第i次游玩的第s_i首歌曲, ACC为a_i %
    // 定数和ACC两位小数，不带百分号
    // 误差要求不大于10的-6次方
    int N,M;
    scanf("%d %d",&N,&M);

    double d[N]; //定数
    int i;
    for (i=0;i<N;i++) {
        scanf("%lf",&d[i]);
    }

    //计算每首歌的最高rating
    int song;
    double rate[N]; //存储
    for (i=0;i<N;i++) {
        rate[i]=0.00;
    }
    double acc;
    double rating; //临时计算
    for (i=0;i<M;i++) {
        scanf("%d %lf",&song,&acc);
        if (97.50-acc<eps) {
            rating=0;
        } else {
            rating=d[song-1]+2.15*((acc-97.50)/(100.90-97.50));
        }
        if (rating-rate[song-1]>eps) {
            rate[song-1]=rating;
        }
    }

    //求B30
    double b[30];
    for (i=0;i<30;i++) {
        b[i]=0.00;
    }
    int j,k;
    for (i=0;i<N;i++) {
        for (j=0;j<30;j++) {
            if (rate[i]-b[j]>eps) {
                for (k=29;k>j;k--) {
                    b[k]=b[k-1];
                }
                b[j]=rate[i];
                break;
            }
        }
    }

    double finalrating=0;
    for (i=0;i<30;i++) {
        finalrating+=b[i];
    }
    finalrating/=30;
    printf("%.10f\n",finalrating);

    return 0;
}
```

判题结果：答案正确

## 复盘

- **错在哪**：16:10 和 16:16 两次答案错误，都是插入前 30 名时只写了一句 b[j]=rate[i] 就 break，忘了把后面的元素往后挪一位，等于把第 j 位直接覆盖掉；16:42 第三次补上 for (k=29;k>j;k--) b[k]=b[k-1] 才通过。
- **代价**：单题 90 分钟，其中 31 分钟是提交后的试错，这把后续整段节奏压掉了。
- **怎么避免**：手写插入的时候「后移」是必做的一步，写完拿一个会真的插到中间的数据手算一遍；这类固定大小 30 的榜，用插入思路本身没问题，但要连同下标一起核对。
- **顺带**：材料里这题 ACC 的分支方向与题面相反（图片转文字时转反了），以牛客的提交记录为准。
