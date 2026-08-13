# M. [NOIP 2002 普及组] 选数

## 核心思路

从 `n` 个数中选出 `k` 个数，如果它们的和是素数，就计入答案。

因为 `n` 通常较小，可以用 DFS 枚举所有选法。递归时记录当前选到的位置、已经选了几个数、当前和。

## 实现要点

- DFS 参数：当前位置 `idx`、已选数量 `cnt`、当前和 `sum`。
- 如果 `cnt == k`，判断 `sum` 是否为素数。
- 每次选择一个比上次下标更大的数，避免重复组合。

## 复杂度

时间复杂度：`O(C(n,k) * sqrt(S))`  
空间复杂度：`O(k)`

## 参考代码

```cpp
#include <cmath>
#include <iostream>
using namespace std;

int n, k;
int a[25];
int ans = 0;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int start, int cnt, int sum) {
    if (cnt == k) {
        if (isPrime(sum)) {
            ans++;
        }
        return;
    }

    for (int i = start; i <= n; i++) {
        dfs(i + 1, cnt + 1, sum + a[i]);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
```
