# N. 迷宫

## 核心思路

题目要求统计从起点走到终点的方案数，每个格子最多经过一次，并且不能走到障碍物上。

这种题不是求最短路，而是求所有可行路径数量，所以用 DFS 回溯枚举路径。

## 实现要点

- 用 `blocked` 标记障碍物。
- 用 `vis` 标记当前路径中已经走过的位置。
- DFS 每次向四个方向扩展。
- 走到终点时答案加一。
- 回溯时要取消当前位置的访问标记，方便其他路径继续使用。

## 复杂度

时间复杂度：最坏情况下为指数级  
空间复杂度：`O(nm)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 10;

bool blocked[N][N];
bool vis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, t;
int sx, sy, fx, fy;
int ans = 0;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }
        if (blocked[nx][ny] || vis[nx][ny]) {
            continue;
        }

        vis[nx][ny] = true;
        dfs(nx, ny);
        vis[nx][ny] = false;
    }
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        blocked[x][y] = true;
    }

    vis[sx][sy] = true;
    dfs(sx, sy);
    cout << ans << endl;

    return 0;
}
```
