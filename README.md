# luogu 50道基础题
## B题 上学迟到【向上取整公式】
```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int s, v;
    cin >> s >> v;

    int travel = (s + v - 1) / v;
    int start = 8 * 60 - travel - 10;

    if (start < 0) {
        start += 24 * 60;
    }

    int hour = start / 60;
    int minute = start % 60;

    cout << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << minute << endl;

    return 0;
}
```
头文件是iomanip
setw(2)设置紧跟其后的一次输出宽度为2
不足位数默认填充是空格，超出位数可以全部显示
setfill('0') 全局生效，位数不足时填充字符是'0'
## D 10进制数转化【除每一位然后reverse】
把十进制整数 `n` 不断对目标进制 `x` 取余，得到的余数就是从低位到高位的每一位；然后再把 `n` 更新为 `n / x`，直到 `n` 变为 `0`。

由于先得到的是最低位，最后需要把结果反转输出。

当余数大于等于 `10` 时，用大写字母表示
### 参考代码

```cpp
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    string ans;
    while (n > 0) {
        int r = n % x;
        if (r < 10) {
            ans.push_back(char('0' + r));
        } else {
            ans.push_back(char('A' + r - 10));
        }
        n /= x;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
```
reverse函数需要头文件algorithm,可用于string和vector
# E. x 进制转 10 进制

### 核心思路

从高位到低位扫描字符串 `S`，用秦九韶算法（逐步累乘）把 `x` 进制数转换成十进制：

```text
ans = ans * x + 当前位的数值
```
### 核心代码

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    string s;
    cin >> x >> s;

    long long ans = 0;
    for (char c : s) {
        int d;
        if (c >= '0' && c <= '9') {
            d = c - '0';
        } else {
            d = c - 'A' + 10;
        }
        ans = ans * x + d;
    }

    cout << ans << endl;
    return 0;
}
```
# H 质数筛选【1不是质数，i*i<=x】
- 先建立 `isPrime` 数组。
- 质数筛从 2 开始处理。


### 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (isPrime(x)) {
            cout << x << " ";
        }
    }

    return 0;
}
```
# I 旗鼓相当的对手【结构体】
```cpp
struct Student {
    string name;
    int chinese;
    int math;
    int english;
    int total;
};
Student a[1005];
```
