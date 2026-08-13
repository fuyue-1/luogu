# W. [NOIP 2005 普及组] 采药

## 核心思路

这是 01 背包问题。每株草药只能采一次，有采药时间和价值，要求在总时间不超过 `T` 的情况下获得最大价值。

设 `dp[j]` 表示总时间不超过 `j` 时能获得的最大价值。

对于每株草药，从大到小枚举时间，避免同一株草药被重复选择。

## 实现要点

- 读入总时间 `T` 和草药数量 `m`。
- 对每株草药读入时间 `cost` 和价值 `value`。
- 倒序枚举 `j`：

```text
dp[j] = max(dp[j], dp[j - cost] + value)
```

## 复杂度

时间复杂度：`O(Tm)`  
空间复杂度：`O(T)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

int dp[1005];

int main() {
    int T, m;
    cin >> T >> m;

    for (int i = 1; i <= m; i++) {
        int cost, value;
        cin >> cost >> value;

        for (int j = T; j >= cost; j--) {
            dp[j] = max(dp[j], dp[j - cost] + value);
        }
    }

    cout << dp[T] << endl;
    return 0;
}
```
