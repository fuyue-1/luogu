# P. [USACO11OPEN] Corn Maze S

## 核心思路

这是带传送门的迷宫最短路问题。

从起点出发，每次可以向四个方向走一步。如果走到一个大写字母传送门，就会立即传送到相同字母的另一个位置。

因为每次移动代价相同，所以使用 BFS。第一次到达终点时就是最短步数。

## 实现要点

- 读入地图，记录起点 `@`、终点 `=`。
- 对每个大写字母记录两个传送门位置。
- BFS 扩展四个方向。
- 如果新位置是传送门，就跳到对应的另一个传送门。
- 传送完成后再判断目标位置是否已经访问过。

## 复杂度

时间复杂度：`O(nm)`  
空间复杂度：`O(nm)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 305;

char g[N][N];
int dist[N][N];
vector<pair<int, int>> portal[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int n, m;
    cin >> n >> m;

    int sx = 0, sy = 0;
    int tx = 0, ty = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            dist[i][j] = -1;
            if (g[i][j] == '@') {
                sx = i, sy = j;
            } else if (g[i][j] == '=') {
                tx = i, ty = j;
            } else if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
                portal[g[i][j] - 'A'].push_back({i, j});
            }
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

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (g[nx][ny] == '#') {
                continue;
            }

            if (g[nx][ny] >= 'A' && g[nx][ny] <= 'Z') {
                int id = g[nx][ny] - 'A';
                auto a = portal[id][0];
                auto b = portal[id][1];
                if (nx == a.first && ny == a.second) {
                    nx = b.first;
                    ny = b.second;
                } else {
                    nx = a.first;
                    ny = a.second;
                }
            }

            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[tx][ty] << endl;
    return 0;
}
```
