# R. 天干地支

## 核心思路

天干每 10 年循环一次，地支每 12 年循环一次，所以组合每 60 年一个周期。根据给定年份和基准年份的差值取模即可。

## 实现要点

- 准备天干数组和地支数组。
- 选择题目给定的基准年份。
- 计算年份差，并分别对 10 和 12 取模。
- 注意负数取模时要转成非负结果。

## 复杂度

时间复杂度：O(1)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int year;
    cin >> year;

    string stem[] = {"jia", "yi", "bing", "ding", "wu",
                     "ji", "geng", "xin", "ren", "gui"};
    string branch[] = {"zi", "chou", "yin", "mao", "chen", "si",
                       "wu", "wei", "shen", "you", "xu", "hai"};

    int stemIndex = (6 + (year - 2020) % 10 + 10) % 10;
    int branchIndex = (0 + (year - 2020) % 12 + 12) % 12;

    cout << stem[stemIndex] << branch[branchIndex] << endl;
    return 0;
}
```
