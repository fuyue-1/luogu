# O. 马的遍历

## 核心思路

马在棋盘上有 8 种跳法，每次跳一步。要求从起点出发，到达棋盘上每个位置的最少步数。

因为每次移动代价相同，所以使用 BFS。第一次访问到某个格子时，得到的就是最短步数。

## 实现要点

- 初始化所有位置距离为 `-1`。
- 起点距离为 `0`。
- BFS 扩展 8 个方向。
- 没访问过且在棋盘内的位置入队。

## 复杂度

时间复杂度：`O(nm)`  
空间复杂度：`O(nm)`

## 参考代码

```cpp
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;

const int N = 405;

int dist[N][N];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << left << setw(5) << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}
```
