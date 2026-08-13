# S. 邮递员送信

## 核心思路

邮递员从 `1` 号点出发给所有点送信，最后还要回到 `1` 号点。图是有向图，所以从 `1` 到各点的距离和各点回到 `1` 的距离不一定相同。

可以做两次最短路：

- 在原图上从 `1` 跑 Dijkstra，得到 `1 -> i` 的最短路。
- 在反图上从 `1` 跑 Dijkstra，得到 `i -> 1` 的最短路。

答案是所有点往返距离之和。

## 实现要点

- 建原图和反图。
- 分别跑一次 Dijkstra。
- 累加 `dist1[i] + dist2[i]`。

## 复杂度

时间复杂度：`O((n + m) log n)`  
空间复杂度：`O(n + m)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to, w;
};

vector<long long> dijkstra(int s, vector<vector<Edge>>& g) {
    int n = g.size() - 1;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    dist[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();

        long long d = cur.first;
        int u = cur.second;

        if (d != dist[u]) {
            continue;
        }

        for (auto e : g[u]) {
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                q.push({dist[e.to], e.to});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n + 1), rg(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        rg[y].push_back({x, z});
    }

    vector<long long> go = dijkstra(1, g);
    vector<long long> back = dijkstra(1, rg);

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += go[i] + back[i];
    }

    cout << ans << endl;
    return 0;
}
```
