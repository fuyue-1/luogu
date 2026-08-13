# Z. [NOIP 2002 普及组] 过河卒

## 核心思路

卒从 `(0, 0)` 走到 `(n, m)`，每次只能向右或向下走。棋盘上有马控制的位置不能经过。

先标记马所在位置和马能攻击到的位置，这些位置都不能走。

然后用动态规划统计路径数：

```text
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
```

如果 `(i, j)` 被马控制，则 `dp[i][j] = 0`。

## 实现要点

- 坐标从 `0` 开始，可以整体加 `1` 避免边界问题。
- 标记马的位置和 8 个攻击位置。
- 从起点开始递推。
- 路径数可能较大，使用 `long long`。

## 复杂度

时间复杂度：`O(nm)`  
空间复杂度：`O(nm)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 25;

bool blocked[N][N];
long long dp[N][N];

int dx[9] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
int dy[9] = {0, 2, -2, 1, -1, 2, -2, 1, -1};

int main() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    n++, m++, hx++, hy++;

    for (int i = 0; i < 9; i++) {
        int x = hx + dx[i];
        int y = hy + dy[i];
        if (x >= 1 && x <= n && y >= 1 && y <= m) {
            blocked[x][y] = true;
        }
    }

    dp[1][1] = blocked[1][1] ? 0 : 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (blocked[i][j] || (i == 1 && j == 1)) {
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
```
