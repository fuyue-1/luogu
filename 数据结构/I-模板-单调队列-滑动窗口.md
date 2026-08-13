# I. 【模板】单调队列 / 滑动窗口

## 核心思路

给定长度为 `n` 的序列，求每个长度为 `k` 的连续窗口中的最小值和最大值。

可以用单调队列维护窗口内可能成为答案的元素下标。

- 求最小值时，队列中元素值保持单调递增。
- 求最大值时，队列中元素值保持单调递减。

队首始终是当前窗口的最优值。

## 实现要点

- 队列中存下标，不直接存值。
- 每次加入新元素前，弹出队尾中不可能成为答案的元素。
- 如果队首下标已经滑出窗口，就弹出队首。
- 当 `i >= k` 时输出当前窗口答案。

## 复杂度

时间复杂度：`O(n)`  
空间复杂度：`O(n)`

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int N = 1000005;

int a[N], q[N];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (head <= tail && q[head] <= i - k) {
            head++;
        }
        while (head <= tail && a[q[tail]] >= a[i]) {
            tail--;
        }
        q[++tail] = i;
        if (i >= k) {
            cout << a[q[head]] << ' ';
        }
    }
    cout << endl;

    head = 1, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (head <= tail && q[head] <= i - k) {
            head++;
        }
        while (head <= tail && a[q[tail]] <= a[i]) {
            tail--;
        }
        q[++tail] = i;
        if (i >= k) {
            cout << a[q[head]] << ' ';
        }
    }
    cout << endl;

    return 0;
}
```
