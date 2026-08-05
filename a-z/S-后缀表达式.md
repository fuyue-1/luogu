# S. 后缀表达式

## 核心思路

使用栈计算后缀表达式。遇到数字就入栈，遇到运算符就从栈中取出两个数计算，再把结果压回栈中。

## 实现要点

- 数字可能不止一位，要完整读入。
- 遇到运算符时，注意两个操作数的顺序。
- 对于减法和除法，先弹出的数是右操作数。
- 表达式结束后，栈顶就是最终答案。

## 复杂度

时间复杂度：O(n)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    char ch;

    while (cin >> ch && ch != '@') {
        if (ch >= '0' && ch <= '9') {
            int num = ch - '0';
            while (cin >> ch && ch >= '0' && ch <= '9') {
                num = num * 10 + ch - '0';
            }
            st.push(num);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (ch == '+') {
                st.push(a + b);
            } else if (ch == '-') {
                st.push(a - b);
            } else if (ch == '*') {
                st.push(a * b);
            } else {
                st.push(a / b);
            }
        }
    }

    cout << st.top() << endl;
    return 0;
}
```
