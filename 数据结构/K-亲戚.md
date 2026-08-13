# K. 亲戚

## 核心思路

判断两个人是否属于同一个亲戚关系集合，可以使用并查集。

每给出一对亲戚关系，就把两个人所在集合合并。查询时判断两个人的祖先是否相同即可。

## 实现要点

- `fa[x]` 表示 `x` 的父节点。
- `find(x)` 查找集合代表元，并进行路径压缩。
- `merge(x, y)` 合并两个集合。
- 查询时比较 `find(x)` 和 `find(y)`。

## 复杂度

时间复杂度：近似 `O(m + p)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 5005;

int fa[N];

int find(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        fa[find(x)] = find(y);
    }

    while (p--) {
        int x, y;
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes" : "No") << endl;
    }

    return 0;
}
```
