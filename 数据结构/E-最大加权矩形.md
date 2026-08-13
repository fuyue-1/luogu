# E. 最大加权矩形

## 核心思路

要求矩阵中权值和最大的子矩形，可以枚举子矩形的上下边界，把二维问题压缩成一维最大子段和问题。

固定上边界 `top` 和下边界 `bottom` 后，每一列在这两行之间的和可以看作一个一维数组。此时问题变成求这个数组的最大连续子段和。

## 实现要点

- 枚举上边界 `top`。
- 用数组 `col[j]` 维护从 `top` 到当前 `bottom` 第 `j` 列的和。
- 每增加一行 `bottom`，更新 `col`。
- 对 `col` 做一次最大子段和。

## 复杂度

时间复杂度：`O(n^3)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 105;

int a[N][N], col[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = -1e9;

    for (int top = 1; top <= n; top++) {
        for (int j = 1; j <= n; j++) {
            col[j] = 0;
        }

        for (int bottom = top; bottom <= n; bottom++) {
            for (int j = 1; j <= n; j++) {
                col[j] += a[bottom][j];
            }

            int cur = col[1];
            ans = max(ans, cur);
            for (int j = 2; j <= n; j++) {
                cur = max(col[j], cur + col[j]);
                ans = max(ans, cur);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
```
