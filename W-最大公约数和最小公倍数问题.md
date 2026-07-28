# W. 最大公约数和最小公倍数问题

## 核心思路

若两个数的最大公约数为 `x`，最小公倍数为 `y`，则这两个数可以写成 `x * a` 和 `x * b`。此时需要满足：

```text
a * b = y / x
gcd(a, b) = 1
```

## 实现要点

- 如果 `y` 不能被 `x` 整除，则没有答案。
- 枚举 `a`，令 `b = (y / x) / a`。
- 只有 `a * b = y / x` 且 `gcd(a, b) = 1` 时才计数。
- 注意有序数对和无序数对的统计方式要按题目要求处理。

## 复杂度

时间复杂度：O(sqrt(y / x) log n)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    long long x, y;
    cin >> x >> y;

    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long n = y / x;
    long long ans = 0;

    for (long long a = 1; a * a <= n; a++) {
        if (n % a != 0) {
            continue;
        }

        long long b = n / a;
        if (gcd(a, b) == 1) {
            ans += (a == b ? 1 : 2);
        }
    }

    cout << ans << endl;
    return 0;
}
```
