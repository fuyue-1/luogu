# M. 扫雷游戏

## 核心思路

遍历整个地图。遇到地雷直接输出地雷符号，遇到空格则统计它周围八个方向的地雷数量。

## 实现要点

- 定义八个方向数组，方便检查周围格子。
- 判断相邻位置时要检查是否越界。
- 地雷位置保持不变。
- 非地雷位置输出周围地雷数量。

## 复杂度

时间复杂度：O(nm)  
空间复杂度：O(nm)

## 参考代码

```cpp
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char a[105][105];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                cout << '*';
                continue;
            }

            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '*') {
                    cnt++;
                }
            }
            cout << cnt;
        }
        cout << endl;
    }

    return 0;
}
```
