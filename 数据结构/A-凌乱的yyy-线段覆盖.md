# A. 凌乱的yyy / 线段覆盖

## 核心思路

这是经典的区间选择问题：给出若干线段，要求选出尽量多的互不相交线段。

贪心策略是：按照线段右端点从小到大排序，每次选择当前能选的、结束最早的线段。这样可以给后面的线段留下尽可能大的空间。

## 实现要点

- 将每条线段存成 `(l, r)`。
- 按 `r` 从小到大排序。
- 维护当前已经选择线段的结束位置 `last`。
- 如果当前线段左端点 `>= last`，就可以选择它。

## 复杂度

时间复杂度：`O(n log n)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int l, r;
};

int main() {
    int n;
    cin >> n;

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end(), [](Node x, Node y) {
        return x.r < y.r;
    });

    int ans = 0;
    int last = -1;

    for (auto x : a) {
        if (x.l >= last) {
            ans++;
            last = x.r;
        }
    }

    cout << ans << endl;
    return 0;
}
```
