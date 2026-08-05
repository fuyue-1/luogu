# D. 数字直角三角形

## 核心思路

按照行列输出递增数字，第一行输出 `n` 个数，第二行输出 `n - 1` 个数，依次形成左对齐的直角三角形。

## 实现要点

- 用一个变量记录当前要输出的数字。
- 外层循环控制行数，内层循环控制每行输出个数。
- 每个数字通常需要按两位格式输出，不足两位补 0。

## 复杂度

时间复杂度：O(n^2)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            cout << setw(2) << setfill('0') << num++;
        }
        cout << endl;
    }

    return 0;
}
```
