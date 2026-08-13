# Y. 两个排列的最长公共子序列

## 核心思路

两个序列都是排列时，可以把最长公共子序列转化为最长上升子序列。

先记录第一个排列中每个数的位置 `pos[x]`。然后把第二个排列中的每个数 `b[i]` 转换成 `pos[b[i]]`。

这样问题变成：在转换后的序列中求最长上升子序列长度。

## 实现要点

- `pos[x]` 表示 `x` 在第一个排列中的位置。
- 将第二个排列转换为位置序列。
- 对位置序列求 LIS。
- 用 `lower_bound` 优化到 `O(n log n)`。

## 复杂度

时间复杂度：`O(n log n)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

int pos[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    vector<int> lis;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int v = pos[x];

        auto it = lower_bound(lis.begin(), lis.end(), v);
        if (it == lis.end()) {
            lis.push_back(v);
        } else {
            *it = v;
        }
    }

    cout << lis.size() << endl;
    return 0;
}
```
