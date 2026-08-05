# Y. A-B 数对

## 核心思路

题目要求统计满足 `A - B = C` 的数对数量。可以将式子转化为查找 `A - C` 是否出现过。

## 实现要点

- 使用哈希表统计每个数出现的次数。
- 遍历每个数 `A`，答案加上 `A - C` 的出现次数。
- 如果使用排序，也可以用二分查找统计目标值出现次数。
- 注意重复数字会产生多个数对，不能只判断是否存在。

## 复杂度

时间复杂度：O(n) 或 O(n log n)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> a(n);
    unordered_map<long long, long long> cnt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[a[i] - c];
    }

    cout << ans << endl;
    return 0;
}
```
