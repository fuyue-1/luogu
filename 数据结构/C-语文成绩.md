# C. 语文成绩

## 核心思路

这类题通常是区间加法后查询最终最小值，可以用差分数组优化。

设原数组为 `a`，差分数组为 `d`：

```text
d[i] = a[i] - a[i - 1]
```

如果要给区间 `[l, r]` 全部加上 `x`，只需要：

```text
d[l] += x
d[r + 1] -= x
```

最后对差分数组求前缀和，就能还原修改后的成绩。

## 实现要点

- 读入原成绩时建立差分数组。
- 每次区间修改只改两个位置。
- 所有操作结束后求前缀和。
- 扫描得到最终最小成绩。

## 复杂度

时间复杂度：`O(n + m)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 5000005;

long long d[N];

int main() {
    int n, m;
    cin >> n >> m;

    long long last = 0;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        d[i] = x - last;
        last = x;
    }

    while (m--) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }

    long long cur = 0;
    long long ans = 1e18;
    for (int i = 1; i <= n; i++) {
        cur += d[i];
        ans = min(ans, cur);
    }

    cout << ans << endl;
    return 0;
}
```
