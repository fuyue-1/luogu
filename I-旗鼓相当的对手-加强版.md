# I. 旗鼓相当的对手 - 加强版

## 核心思路

枚举每一对同学，判断三科成绩差和总分差是否都满足“旗鼓相当”的条件。加强版需要输出满足条件的两名同学姓名。

## 实现要点

- 每名同学需要读入姓名和三科成绩。
- 对于两名同学，分别比较三科成绩差。
- 三科成绩差通常要求都不超过 5。
- 总分差通常要求不超过 10。
- 满足条件时，按照枚举顺序输出两名同学的姓名。

## 复杂度

时间复杂度：O(n^2)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int chinese;
    int math;
    int english;
    int total;
};

int main() {
    int n;
    cin >> n;

    Student a[1005];
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].chinese >> a[i].math >> a[i].english;
        a[i].total = a[i].chinese + a[i].math + a[i].english;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(a[i].chinese - a[j].chinese) <= 5 &&
                abs(a[i].math - a[j].math) <= 5 &&
                abs(a[i].english - a[j].english) <= 5 &&
                abs(a[i].total - a[j].total) <= 10) {
                cout << a[i].name << " " << a[j].name << endl;
            }
        }
    }

    return 0;
}
```
