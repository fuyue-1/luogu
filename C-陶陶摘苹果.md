# C. 陶陶摘苹果

## 核心思路

陶陶能够到的高度是自己的身高加上板凳高度。遍历每个苹果的高度，统计能够摘到的苹果数量。

## 实现要点

- 读入 10 个苹果的高度。
- 读入陶陶的身高。
- 如果 `苹果高度 <= 陶陶身高 + 30`，答案加一。

## 复杂度

时间复杂度：O(10)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
using namespace std;

int main() {
    int apple[10];
    for (int i = 0; i < 10; i++) {
        cin >> apple[i];
    }

    int height;
    cin >> height;

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (apple[i] <= height + 30) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
```
