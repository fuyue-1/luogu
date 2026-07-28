# P. 幂次方

## 核心思路

将一个数拆成若干个 2 的幂之和，再递归表示指数部分。

例如一个数可以写成：

```text
n = 2^a + 2^b + ...
```

指数 `a`、`b` 也继续用同样的方法表示。

## 实现要点

- 从高位到低位寻找二进制中为 1 的位置。
- 每一项输出成 `2`、`2(0)` 或 `2(表达式)` 的形式。
- 多项之间用 `+` 连接。
- 递归出口要处理 0 和 1。

## 复杂度

时间复杂度：O(log n)  
空间复杂度：O(log n)

## 参考代码

```cpp
#include <iostream>
#include <string>
using namespace std;

string solve(int n) {
    string result;

    for (int i = 15; i >= 0; i--) {
        if ((n >> i) & 1) {
            string term;
            if (i == 0) {
                term = "2(0)";
            } else if (i == 1) {
                term = "2";
            } else {
                term = "2(" + solve(i) + ")";
            }

            if (!result.empty()) {
                result += "+";
            }
            result += term;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
```
