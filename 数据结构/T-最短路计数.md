# T. 最短路计数

## 核心思路

在无权图中，从 `1` 号点到其他点的最短路可以用 BFS 求出。同时可以统计最短路条数。

当从 `u` 走到 `v` 时：

- 如果 `v` 第一次被访问，说明找到它的最短路，`cnt[v] = cnt[u]`。
- 如果 `dist[v] == dist[u] + 1`，说明又找到一条到 `v` 的最短路，累加 `cnt[u]`。

## 实现要点

- `dist[i]` 表示从 `1` 到 `i` 的最短距离。
- `cnt[i]` 表示从 `1` 到 `i` 的最短路条数。
- BFS 从 `1` 开始。
- 答案对 `100003` 取模。

## 复杂度

时间复杂度：`O(n + m)`  
空间复杂度：`O(n + m)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MOD = 100003;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> dist(n + 1, -1);
    vector<int> cnt(n + 1, 0);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    cnt[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            //BFS 特性，第一次访问就是最短路
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
                //这里不 push (v) 进队列！ v 已经进过队列，BFS 不需要重复入队。
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}
```
