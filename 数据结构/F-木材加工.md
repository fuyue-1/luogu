# F. 木材加工

## 核心思路

给出若干根木材，要求切出至少 `k` 段长度相同的小木段，并让小木段长度尽可能大。

答案具有单调性：如果长度 `x` 可以切出至少 `k` 段，那么更短的长度也一定可以；如果长度 `x` 不可以，那么更长的长度也不可以。

因此可以二分答案。

## 实现要点

- 二分小木段长度 `mid`。
- 统计所有木材能切出多少段 `len[i] / mid`。
- 如果总段数不少于 `k`，说明 `mid` 可行，尝试更大。
- 否则尝试更小。

## 复杂度

时间复杂度：`O(n log V)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int l = 1, r = mx, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        long long cnt = 0;

        for (int x : a) {
            cnt += x / mid;
        }

        if (cnt >= k) {
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
