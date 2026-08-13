# Q. [JOI 2007 Final] 郁闷的记者

## 核心思路

题目给出若干场比赛结果：如果 `x` 能打败 `y`，那么 `x` 的排名必须在 `y` 前面。

这就是一个有向图拓扑排序问题：

```text
x -> y
```

表示 `x` 必须排在 `y` 前面。

拓扑排序得到的顺序就是一种合法排名。

同时还要判断是否存在另一种合法排名。判断方法是：在拓扑排序过程中，如果某一时刻入度为 `0` 的点不止一个，那么当前可以选择多个队伍放到下一名，说明排名不唯一。

## 实现要点

- 建立有向图，边 `x -> y` 表示 `x` 排在 `y` 前。
- 统计每个点的入度。
- 将所有入度为 `0` 的点放入队列。
- 每次取出一个点作为当前排名。
- 如果某次取点前队列大小大于 `1`，说明存在多种排名，最后输出 `1`。
- 如果整个过程中队列大小始终不超过 `1`，说明排名唯一，最后输出 `0`。

## 复杂度

时间复杂度：`O(n + m)`  
空间复杂度：`O(n + m)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    bool notUnique = false;

    while (!q.empty()) {
        if (q.size() > 1) {
            notUnique = true;
        }

        int u = q.front();
        q.pop();
        ans.push_back(u);

        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int x : ans) {
        cout << x << endl;
    }

    cout << (notUnique ? 1 : 0) << endl;
    return 0;
}
```
