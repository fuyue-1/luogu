# D. 地毯

## 核心思路

题目通常给出一个 `n * n` 的网格和若干次铺地毯操作，每次覆盖一个矩形区域，要求输出每个位置被覆盖的次数。

可以使用二维差分。对矩形 `(x1, y1)` 到 `(x2, y2)` 加 `1`：

```text
d[x1][y1] += 1
d[x2 + 1][y1] -= 1
d[x1][y2 + 1] -= 1
d[x2 + 1][y2 + 1] += 1
```

最后对二维差分求前缀和，即可得到每个点的覆盖次数。

## 实现要点

- 建立二维差分数组。
- 每次矩形修改只改四个角。
- 最后用二维前缀和还原答案。

## 复杂度

时间复杂度：`O(n^2 + m)`  
空间复杂度：`O(n^2)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 1005;

int d[N][N];

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1]++;
        d[x2 + 1][y1]--;
        d[x1][y2 + 1]--;
        d[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (j > 1) {
                cout << ' ';
            }
            cout << d[i][j];
        }
        cout << endl;
    }

    return 0;
}
```
