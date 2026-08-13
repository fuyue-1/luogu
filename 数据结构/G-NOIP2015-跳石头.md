# G. [NOIP 2015 提高组] 跳石头

## 核心思路

题目要求移走不超过 `m` 块石头，使得相邻石头之间的最小距离尽可能大。

答案具有单调性：如果最小距离 `x` 可以做到，那么更小的距离也可以做到；如果 `x` 做不到，那么更大的距离也做不到。

因此二分最小距离。

## 实现要点

- 把起点 `0` 和终点 `L` 也看作石头。
- 二分答案 `mid`。
- 从左到右贪心检查：如果当前石头到上一块保留石头的距离小于 `mid`，就必须移走当前石头。
- 统计需要移走的石头数是否 `<= m`。

## 复杂度

时间复杂度：`O(n log L)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, n, m;
    cin >> L >> n >> m;

    vector<int> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = L;

    int l = 1, r = L, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int last = 0;
        int removed = 0;

        for (int i = 1; i <= n + 1; i++) {
            if (a[i] - a[last] < mid) {
                removed++;
            } else {
                last = i;
            }
        }

        if (removed <= m) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
```
