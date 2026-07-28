# Q. 蛇形方阵

## 核心思路

按照“右、下、左、上”的方向循环填数。每次走到边界或下一个位置已经填过，就改变方向。

## 实现要点

- 用二维数组保存答案。
- 设置方向数组：右、下、左、上。
- 每填入一个数后，尝试走到下一个位置。
- 如果越界或已访问，则转向。

## 复杂度

时间复杂度：O(n^2)  
空间复杂度：O(n^2)

## 参考代码

```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[15][15] = {};
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    int x = 0, y = 0, dir = 0;
    for (int num = 1; num <= n * n; num++) {
        a[x][y] = num;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
```
