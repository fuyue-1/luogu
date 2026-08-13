# V. [SCOI2005] 繁忙的都市

## 核心思路

题目要求选择一些道路连接所有路口，并且让选中道路中的最大边权尽可能小。

这可以用最小生成树解决。Kruskal 算法按边权从小到大选边，当所有点连通时，最后选中的边权就是答案。

## 实现要点

- 按道路权值从小到大排序。
- 用并查集维护连通性。
- 如果一条边连接两个不同连通块，就选它。
- 选够 `n - 1` 条边后结束。

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
    int x, y, w;
};

int fa[305];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].w;
    }

    sort(e.begin(), e.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    int cnt = 0;
    int ans = 0;

    for (auto edge : e) {
        int fx = find(edge.x);
        int fy = find(edge.y);

        if (fx != fy) {
            fa[fx] = fy;
            cnt++;
            ans = edge.w;
            if (cnt == n - 1) {
                break;
            }
        }
    }

    cout << n - 1 << " " << ans << endl;
    return 0;
}
```
