# K. 生日相遇问题

## 核心思路

这类题通常需要围绕日期进行模拟或枚举。按照题目给出的年份、月份、日期规则，逐个判断是否满足“生日相遇”的条件。

## 实现要点

- 先写函数判断闰年。
- 再准备每个月的天数。
- 枚举日期时要注意月份进位和年份变化。
- 判断条件尽量单独写成函数，避免主逻辑混乱。

## 复杂度

时间复杂度：O(枚举范围)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
using namespace std;

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDayOfYear(int month, int day, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(year)) {
        days[1] = 29;
    }

    if (month == 2 && day == 29 && !isLeap(year)) {
        day = 28;
    }

    int result = 0;
    for (int i = 0; i < month - 1; i++) {
        result += days[i];
    }
    return result + day;
}

int main() {
    int m, d1, n, d2, k;
    cin >> m >> d1 >> n >> d2 >> k;

    int firstWeekday = 3; // 2025 年 1 月 1 日是星期三
    bool found = false;

    for (int year = 2025; year < 2025 + k; year++) {
        int day1 = getDayOfYear(m, d1, year);
        int day2 = getDayOfYear(n, d2, year);

        int week1 = (firstWeekday + day1 - 1) % 7;
        int week2 = (firstWeekday + day2 - 1) % 7;

        if (week1 == week2) {
            cout << year << endl;
            found = true;
        }
        //// 用2025年的总天数(365/366)，推算2026年元旦的星期
        firstWeekday = (firstWeekday + (isLeap(year) ? 366 : 365)) % 7;
    }

    if (!found) {
        cout << "No Answer" << endl;
    }

    return 0;
}
```
