# E. 三角形分类

## 核心思路

先将三条边从小到大排序，再判断是否能构成三角形，最后根据边长关系和角度关系分类。

## 实现要点

- 若最短两边之和不大于最长边，则不是三角形。
- 用平方关系判断角度类型：
  - `a^2 + b^2 = c^2`：直角三角形
  - `a^2 + b^2 > c^2`：锐角三角形
  - `a^2 + b^2 < c^2`：钝角三角形
- 再判断是否为等腰或等边三角形。

## 复杂度

时间复杂度：O(1)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(a, a + 3);

    if (a[0] + a[1] <= a[2]) {
        cout << "Not triangle" << endl;
        return 0;
    }

    int x = a[0] * a[0] + a[1] * a[1];
    int y = a[2] * a[2];

    if (x == y) {
        cout << "Right triangle" << endl;
    } else if (x > y) {
        cout << "Acute triangle" << endl;
    } else {
        cout << "Obtuse triangle" << endl;
    }

    if (a[0] == a[1] || a[1] == a[2]) {
        cout << "Isosceles triangle" << endl;
    }
    if (a[0] == a[2]) {
        cout << "Equilateral triangle" << endl;
    }

    return 0;
}
```
