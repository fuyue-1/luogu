# X. 最大子段和

## 核心思路

最大子段和要求在一个序列中找到和最大的连续子序列。

用动态规划维护 `cur`：表示以当前位置结尾的最大子段和。

对于当前数 `a[i]`：

```text
cur = max(a[i], cur + a[i])
```

答案就是所有 `cur` 的最大值。

## 实现要点

- 如果前面的和为负数，就不如从当前位置重新开始。
- 每次更新当前最大子段和。
- 注意全负数情况，答案应该是最大的那个负数。

## 复杂度

时间复杂度：`O(n)`  
空间复杂度：`O(1)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long x;
    cin >> x;

    long long cur = x;
    long long ans = x;

    for (int i = 2; i <= n; i++) {
        cin >> x;
        cur = max(x, cur + x);
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}
```
