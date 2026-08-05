# X. 查找

## 核心思路

在有序数组中查找目标值，使用二分查找可以快速定位。若题目要求输出第一次出现的位置，需要查找左边界。

## 实现要点

- 数组需要保持有序。
- 二分时不要只判断是否存在，还要继续向左收缩，寻找第一次出现的位置。
- 找不到时按题目要求输出指定值，常见为 `-1`。
- 注意输出位置是从 0 开始还是从 1 开始。

## 复杂度

时间复杂度：O(q log n)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int x;
        cin >> x;

        int left = 1;
        int right = n;
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] >= x) {
                if (a[mid] == x) {
                    ans = mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << " ";
    }

    return 0;
}
```
