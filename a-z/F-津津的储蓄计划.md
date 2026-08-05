# F. 津津的储蓄计划

## 核心思路

按月份模拟津津的收支情况。每月先得到 300 元，扣掉预算后，把剩余钱中整百的部分存起来。

## 实现要点

- 如果某个月钱不够用，直接输出 `-月份`。
- 每月剩余的钱中，整百部分存入妈妈那里。
- 最后总钱数为手上的钱加上存款的 120%。

## 复杂度

时间复杂度：O(12)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
using namespace std;

int main() {
    int money = 0;
    int saved = 0;

    for (int month = 1; month <= 12; month++) {
        int cost;
        cin >> cost;

        money += 300;
        money -= cost;

        if (money < 0) {
            cout << -month << endl;
            return 0;
        }

        saved += money / 100 * 100;
        money %= 100;
    }

    cout << money + saved * 120 / 100 << endl;
    return 0;
}
```
