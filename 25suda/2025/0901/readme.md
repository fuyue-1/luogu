# 1. 32之内进制转换

这是十进制转任意进制的基础题。
对于十进制整数 `num`，转换成 `base` 进制时，可以不断取余：

```text
digit = num % base
num = num / base
```

每次得到的 `digit` 是当前最低位。

因此得到的数字顺序是从低位到高位，需要最后反转后输出。

## 数字字符映射

目标进制最大到 `32`，所以一位数字可能是 `0` 到 `31`。

可以准备一个字符表：

```text
0123456789ABCDEFGHIJKLMNOPQRSTUV
```


当余数为 `digit` 时，对应字符就是：

```text
chars[digit]
```

1. 读入 `num` 和 `base`。
2. 定义字符表 `chars`。
3. 如果 `num == 0`，直接输出 `0`。
4. 否则不断执行取余和整除。
5. 将余数对应字符加入字符串。
6. 最后反转字符串并输出。

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, base;
    cin >> num >> base;

    string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUV";

    if (num == 0) {
        cout << 0 << '\n';
        return 0;
    }

    string ans = "";

    while (num > 0) {
        int digit = num % base;
        ans += chars[digit];
        num /= base;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}
```
# 2. Z字形变换2

## 题目描述

给定一个字符串 `s` 和一个正整数 `n`，将字符串按 `"Z"` 字形排列。

排列方式是自上而下、从左到右依次摆放字符。

最后返回按行遍历得到的字符串。

数据范围：

```text
字符串长度不超过 1000
n >= 1
```

## 样例

输入：

```text
University 3
```

输出：

```text
Uetnvriyis
```

## 核心思路

这是一道字符串模拟题。

可以用 `n` 个字符串分别表示 Z 字形中的每一行。

从左到右扫描原字符串，把每个字符放入当前行。

同时维护当前移动方向：

- 向下移动；
- 向上移动。

当到达第 `0` 行时，接下来应该向下走。

当到达第 `n - 1` 行时，接下来应该向上走。

最后把所有行从上到下拼接起来，就是答案。

## 样例解释

字符串为：

```text
University
```

行数为 `3`。

按 Z 字形摆放：

```text
U   e   t
n v r i y
i   s
```

按行读取：

```text
Uet + nvriy + is
```

得到：

```text
Uetnvriyis
```

## 特殊情况

如果 `n == 1`，只有一行，不会形成上下移动。

此时结果就是原字符串本身，直接输出即可。

## 实现要点

1. 读入字符串 `s` 和行数 `n`。
2. 如果 `n == 1`，直接输出 `s`。
3. 定义字符串数组 `rows`，保存每一行的字符。
4. 用 `row` 表示当前所在行。
5. 用 `dir` 表示移动方向，`1` 表示向下，`-1` 表示向上。
6. 每放入一个字符后，更新当前行。
7. 最后拼接所有行并输出。

## 复杂度

设字符串长度为 `len`。

```text
时间复杂度：O(len)
空间复杂度：O(len)
```

## 参考代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    if (n == 1) {
        cout << s << '\n';
        return 0;
    }

    string rows[1005];

    int row = 0;
    int dir = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        rows[row] += s[i];

        if (row == 0) {
            dir = 1;
        } else if (row == n - 1) {
            dir = -1;
        }

        row += dir;
    }

    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += rows[i];
    }

    cout << ans << '\n';

    return 0;
}
```


