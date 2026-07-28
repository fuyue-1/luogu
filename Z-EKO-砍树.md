# Z. EKO / 砍树

## 核心思路

砍树高度越低，得到的木材越多；砍树高度越高，得到的木材越少。因此答案具有单调性，可以二分砍树高度。

## 实现要点

- 二分范围为 `0` 到最高树高。
- 对于一个高度 `mid`，计算所有树超过 `mid` 的部分总和。
- 如果得到的木材不少于目标值，说明高度还可以更高。
- 否则高度需要降低。
- 最后输出满足条件的最大高度。

## 复杂度

时间复杂度：O(n log H)  
空间复杂度：O(1)

## 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> tree(n);
    long long maxHeight = 0;

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        if (tree[i] > maxHeight) {
            maxHeight = tree[i];
        }
    }

    long long left = 0;
    long long right = maxHeight;
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long wood = 0;

        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) {
                wood += tree[i] - mid;
            }
        }

        if (wood >= m) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
```
