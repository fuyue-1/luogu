# luogu 50道基础题
## B题 上学迟到【向上取整公式】
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
setw(2)设置紧跟其后的一次输出宽度为2
不足位数默认填充是空格，超出位数可以全部显示
setfill('0') 全局生效，位数不足时填充字符是'0'