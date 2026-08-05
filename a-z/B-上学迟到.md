# B. 上学迟到

## 核心思路

先计算从家到学校需要的总时间，再从 8:00 往前倒推应该出发的时间。

总时间包括：

```text
路上时间 + 提前准备的 10 分钟
```

## 实现要点

- 路上时间要向上取整，因为不足一分钟也需要算一分钟。
- 将 8:00 转成分钟数，即 480 分钟。
- 如果倒推后时间为负数，需要加上一天的分钟数 1440。
- 输出时小时和分钟都要补前导 0。

## 复杂度

时间复杂度：O(1)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int s, v;
    cin >> s >> v;

    int travel = (s + v - 1) / v;
    int start = 8 * 60 - travel - 10;

    if (start < 0) {
        start += 24 * 60;
    }

    int hour = start / 60;
    int minute = start % 60;

    cout << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << minute << endl;

    return 0;
}
```
