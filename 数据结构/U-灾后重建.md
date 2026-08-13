# U. 灾后重建

## 核心思路

每个村庄有一个重建完成时间，只有重建完成的村庄才能作为路径上的点。

查询 `(x, y, t)` 时，只能使用重建时间不超过 `t` 的村庄。可以按时间顺序逐步把村庄加入 Floyd。

维护一个指针 `k`，表示已经加入了哪些村庄作为中转点。对于每个查询，把所有 `time[k] <= t` 的村庄加入 Floyd 更新。

## 实现要点

- `d[i][j]` 表示当前可用村庄条件下的最短路。
- 村庄按编号给出，并且重建时间通常非降序。
- 对于每个查询时间 `t`，不断加入重建时间 `<= t` 的村庄。
- 如果起点或终点还没重建，或者不可达，输出 `-1`。

## 复杂度

预处理与更新总复杂度：`O(n^3)`  
单次查询复杂度：`O(1)`  
空间复杂度：`O(n^2)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 205;
const int INF = 1e9;

int t[N];
int d[N][N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = (i == j ? 0 : INF);
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        d[x][y] = d[y][x] = min(d[x][y], w);
    }

    int q;
    cin >> q;

    int now = 0;
    while (q--) {
        int x, y, queryTime;
        cin >> x >> y >> queryTime;

        while (now < n && t[now] <= queryTime) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][now] + d[now][j]);
                }
            }
            now++;
        }

        if (t[x] > queryTime || t[y] > queryTime || d[x][y] == INF) {
            cout << -1 << endl;
        } else {
            cout << d[x][y] << endl;
        }
    }

    return 0;
}
```
