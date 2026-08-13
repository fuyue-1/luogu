# R. [HNOI2015] 菜肴制作

## 核心思路

这题本质是拓扑排序。题目给出若干先后关系，要求构造一个合法顺序，并且尽量让编号小的菜更靠前。

常见做法是反向建图，然后用大根堆做拓扑排序，最后将结果反转。

这样可以在满足限制的前提下，让最终序列字典序尽量小。

## 实现要点

- 对限制 `x` 在 `y` 前，反向建边 `y -> x`。
- 统计反向图入度。
- 把入度为 `0` 的点放入大根堆。
- 每次取编号最大的点。
- 得到的序列最后反转输出。
- 如果无法处理所有点，说明有环，输出 `Impossible!`。

## 复杂度

时间复杂度：`O((n + m) log n)`  
空间复杂度：`O(n + m)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            g[y].push_back(x);
            indeg[x]++;
        }

        priority_queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            ans.push_back(u);

            for (int v : g[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if ((int)ans.size() != n) {
            cout << "Impossible!" << endl;
        } else {
            for (int i = n - 1; i >= 0; i--) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
```
