# N. 显示屏

## 核心思路

把每个数字在显示屏上的形状预先存下来，输出时按行拼接每个数字对应的图案。

## 实现要点

- 用数组保存 0 到 9 的显示样式。
- 按显示屏的每一行输出，而不是一个数字一个数字完整输出。
- 多个数字之间要注意空格或间隔格式。
- 重点检查输出格式，避免多余空格。

## 复杂度

时间复杂度：O(数字个数)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    string digit[10][5] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},
        {"..X", "..X", "..X", "..X", "..X"},
        {"XXX", "..X", "XXX", "X..", "XXX"},
        {"XXX", "..X", "XXX", "..X", "XXX"},
        {"X.X", "X.X", "XXX", "..X", "..X"},
        {"XXX", "X..", "XXX", "..X", "XXX"},
        {"XXX", "X..", "XXX", "X.X", "XXX"},
        {"XXX", "..X", "..X", "..X", "..X"},
        {"XXX", "X.X", "XXX", "X.X", "XXX"},
        {"XXX", "X.X", "XXX", "..X", "XXX"}
    };

    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            cout << digit[s[i] - '0'][row];
            if (i != n - 1) {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}
```
