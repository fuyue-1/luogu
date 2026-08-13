# L. 修复公路

## 核心思路

每条公路有修复时间，要求找到最早的时间，使所有村庄连通。

可以按时间从小到大排序道路，然后用并查集逐条合并。如果某一时刻连通块数量变成 `1`，说明所有村庄已经连通，这个时间就是答案。

## 实现要点

- 按道路修复时间排序。
- 初始有 `n` 个连通块。
- 每成功合并两个不同集合，连通块数量减一。
- 连通块数量为 `1` 时输出当前时间。
- 如果最后仍未连通，输出 `-1`。

## 复杂度

时间复杂度：`O(m log m)`  
空间复杂度：`O(n + m)`

## 参考代码

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int x, y, t;
};

const int N = 1005;
int fa[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].t;
    }

    sort(e.begin(), e.end(), [](Edge a, Edge b) {
        return a.t < b.t;
    });

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    int cnt = n;
    for (auto edge : e) {
        int fx = find(edge.x);
        int fy = find(edge.y);
        if (fx != fy) {
            fa[fx] = fy;
            cnt--;
            if (cnt == 1) {
                cout << edge.t << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
```
