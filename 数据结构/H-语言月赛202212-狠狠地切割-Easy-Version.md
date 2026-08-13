# H. [语言月赛202212] 狠狠地切割(Easy Version)

## 核心思路

给定一个序列 `a` 和一个集合 `b`。如果 `a[i]` 出现在集合 `b` 中，那么位置 `i` 就是切割点，需要把这个位置的数删除，并把左右两边分开。

最后要求的是删除所有切割点后，还剩下多少个非空连续片段。

所以可以把问题理解成：统计序列 `a` 中有多少段连续的“非切割点”。

遍历序列时：

- 如果当前数是切割点，说明当前片段结束。
- 如果当前数不是切割点，并且前一个位置不是片段中，那么开启一个新片段，答案加一。

## 实现要点

- 用 `unordered_set` 保存所有切割数字，方便 `O(1)` 判断。
- 由于输入顺序是先给序列 `a`，再给集合 `b`，所以需要先保存序列 `a`。
- 用布尔变量 `inSegment` 表示当前是否处在一个非空片段中。
- 遇到切割点时令 `inSegment = false`。
- 遇到非切割点且 `inSegment == false` 时，说明新片段开始。

## 复杂度

时间复杂度：`O(n + m)`  
空间复杂度：`O(n + m)`

## 参考代码

```cpp
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> cut;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cut.insert(x);
    }

    int ans = 0;
    bool inSegment = false;

    for (int x : a) {
        if (cut.count(x)) {
            inSegment = false;
        } else {
            if (!inSegment) {
                ans++;
                inSegment = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
```
