# A. 肥胖问题

## 核心思路

根据身高和体重计算 BMI，然后按照题目给出的标准分类输出。

BMI 公式：

```text
BMI = 体重 / 身高^2
```

## 实现要点

- 身高一般用米作为单位。
- BMI 要用浮点数计算，不能使用整数除法。
- 按照题目要求判断偏瘦、正常或超重。

## 复杂度

时间复杂度：O(1)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
using namespace std;

int main() {
    double m, h;
    cin >> m >> h;

    double bmi = m / (h * h);

    if (bmi < 18.5) {
        cout << "Underweight" << endl;
    } else if (bmi < 24) {
        cout << "Normal" << endl;
    } else {
        cout << bmi << endl;
        cout << "Overweight" << endl;
    }

    return 0;
}
```
