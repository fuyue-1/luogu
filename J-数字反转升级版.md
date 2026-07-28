# J. 数字反转（升级版）

## 核心思路

将数字看成字符串处理，根据是否有负号、小数点、分数线或百分号，分别反转需要处理的部分。

## 实现要点

- 先判断字符串中是否包含特殊符号。
- 每一段数字单独反转。
- 反转后要去掉多余的前导零。
- 如果结果为空，说明这一段应输出 `0`。
- 负号、百分号、分数线等符号要按原格式保留。

## 复杂度

时间复杂度：O(n)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string reverseIntegerPart(string s) {
    reverse(s.begin(), s.end());
    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') {
        pos++;
    }
    return s.substr(pos);
}

string reverseDecimalPart(string s) {
    reverse(s.begin(), s.end());
    while (s.size() > 1 && s.back() == '0') {
        s.pop_back();
    }
    return s;
}

int main() {
    string s;
    cin >> s;

    if (s.back() == '%') {
        s.pop_back();
        cout << reverseIntegerPart(s) << "%" << endl;
    } else if (s.find('.') != string::npos) {
        int p = s.find('.');
        string left = s.substr(0, p);
        string right = s.substr(p + 1);
        cout << reverseIntegerPart(left) << "." << reverseDecimalPart(right) << endl;
    } else if (s.find('/') != string::npos) {
        int p = s.find('/');
        string left = s.substr(0, p);
        string right = s.substr(p + 1);
        cout << reverseIntegerPart(left) << "/" << reverseIntegerPart(right) << endl;
    } else {
        cout << reverseIntegerPart(s) << endl;
    }

    return 0;
}
```
