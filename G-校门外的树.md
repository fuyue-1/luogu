# G. 校门外的树

## 核心思路

道路上的树可以看作编号为 `0` 到 `L` 的点。对于每个施工区间，将区间内的树标记为被移走，最后统计未被移走的数量。

## 实现要点

- 可以用布尔数组记录每棵树是否被移走。
- 区间 `[l, r]` 两端都包含。
- 最后遍历 `0` 到 `L`，统计没有被标记的树。

## 复杂度

时间复杂度：O(L + mL) 或 O(区间总长度)  
空间复杂度：O(L)

## 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, m;
    cin >> L >> m;

    vector<bool> removed(L + 1, false);

    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;

        for (int j = left; j <= right; j++) {
            removed[j] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i <= L; i++) {
        if (!removed[i]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
```
