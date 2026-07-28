# L. 文字处理软件

## 核心思路

按照指令对字符串进行模拟操作，每读入一条操作，就立即修改当前字符串或输出查询结果。

## 实现要点

- 常见操作包括插入、删除、查找和截取。
- 使用字符串自带函数可以简化实现。
- 注意下标从 0 开始还是从 1 开始，按题目要求转换。
- 每次操作后都要更新当前字符串。

## 复杂度

时间复杂度：O(qn)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    string s;
    cin >> q >> s;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            string t;
            cin >> t;
            s += t;
            cout << s << endl;
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            s = s.substr(a, b);
            cout << s << endl;
        } else if (op == 3) {
            int a;
            string t;
            cin >> a >> t;
            s.insert(a, t);
            cout << s << endl;
        } else if (op == 4) {
            string t;
            cin >> t;
            int pos = s.find(t);
            cout << pos << endl;
        }
    }

    return 0;
}
```
