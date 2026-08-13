# B. [NOIP 2004 提高组] 合并果子

## 核心思路

每次合并两堆果子，消耗为两堆重量之和。为了让总代价最小，每次都应该选择当前最小的两堆合并。

这就是哈夫曼合并问题，可以用小根堆维护所有果子堆。

## 实现要点

- 将所有果子重量放入小根堆。
- 每次取出最小的两个数 `x` 和 `y`。
- 答案加上 `x + y`。
- 将合并后的新堆 `x + y` 放回堆中。
- 直到堆中只剩一堆。

## 复杂度

时间复杂度：`O(n log n)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();

        ans += x + y;
        q.push(x + y);
    }

    cout << ans << endl;
    return 0;
}
```
