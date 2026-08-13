# J. [NOIP 2016 普及组] 海港

## 核心思路

题目要求统计最近 `86400` 秒内到达海港的乘客来自多少个不同国家。

可以用队列维护当前时间窗口内的所有乘客，同时用计数数组记录每个国家当前在窗口内有多少人。

每读入一艘船，就把船上所有乘客加入队列；然后弹出所有时间过期的乘客；最后统计当前仍在窗口内的国家数量。

## 实现要点

- 队列中保存 `(到达时间, 国家)`。
- `cnt[country]` 表示当前窗口内该国家人数。
- 新国家人数从 `0` 变成 `1` 时，不同国家数加一。
- 国家人数从 `1` 变成 `0` 时，不同国家数减一。

## 复杂度

时间复杂度：`O(总乘客数)`  
空间复杂度：`O(总乘客数 + 国家数)`

## 参考代码

```cpp
#include <iostream>
#include <queue>
using namespace std;

const int N = 100005;

int cnt[N];

int main() {
    int n;
    cin >> n;

    queue<pair<int, int>> q;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int t, k;
        cin >> t >> k;

        while (k--) {
            int x;
            cin >> x;
            q.push({t, x});
            if (cnt[x] == 0) {
                ans++;
            }
            cnt[x]++;
        }

        while (!q.empty() && q.front().first <= t - 86400) {
            int x = q.front().second;
            q.pop();
            cnt[x]--;
            if (cnt[x] == 0) {
                ans--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
```
