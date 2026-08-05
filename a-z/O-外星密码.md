# O. 外星密码

## 核心思路

使用递归解析压缩字符串。遇到普通字符直接加入答案，遇到 `[` 时，先读取后面的重复次数，再递归解析括号内内容，最后将解析出的内容重复指定次数。

这题的格式是：

```text
[次数 内容]
```

例如 `AC[3FUN]` 表示 `ACFUNFUNFUN`。

## 实现要点

- 从左到右扫描字符串。
- 遇到普通字符，直接加入当前答案。
- 遇到 `[` 后，先跳过 `[`。
- 读取 `[` 后面的数字，得到重复次数。
- 递归处理括号内部。
- 遇到 `]` 表示当前递归层结束。
- 返回解析出的字符串给上一层继续拼接。

## 复杂度

时间复杂度：O(展开后字符串长度)  
空间复杂度：O(递归深度 + 展开后字符串长度)

## 参考代码

```cpp
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string s;
int pos = 0;

string decode() {
    string result;

    while (pos < (int)s.size() && s[pos] != ']') {
        if (s[pos] == '[') {
            pos++; // 跳过 [

            int times = 0;
            while (pos < (int)s.size() && isdigit(s[pos])) {
                times = times * 10 + s[pos] - '0';
                pos++;
            }

            string inner = decode();
            pos++; // 跳过 ]

            while (times--) {
                result += inner;
            }
        } else {
            result += s[pos];
            pos++;
        }
    }

    return result;
}

int main() {
    cin >> s;
    cout << decode() << endl;
    return 0;
}
```
