# U. 队列安排

## 核心思路

维护每个人左右两边的人，相当于用数组模拟双向链表。插入时修改相邻关系，删除时把该节点从链表中断开。

## 实现要点

- `left[i]` 表示 i 左边的人，`right[i]` 表示 i 右边的人。
- 插入到某人左边或右边时，要同时修改前后节点的指针。
- 删除某人时，如果已经删除过就跳过。
- 最后从队头开始沿 `right` 输出队列。

## 复杂度

时间复杂度：O(n + m)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
using namespace std;

const int MAXN = 100005;

int leftNode[MAXN], rightNode[MAXN];
bool removed[MAXN];

void insertBetween(int l, int r, int x) {
    rightNode[l] = x;
    leftNode[x] = l;
    rightNode[x] = r;
    leftNode[r] = x;
}

int main() {
    int n;
    cin >> n;

    rightNode[0] = 1;
    leftNode[0] = 1;
    leftNode[1] = 0;
    rightNode[1] = 0;

    for (int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;

        if (p == 0) {
            insertBetween(leftNode[k], k, i);
        } else {
            insertBetween(k, rightNode[k], i);
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;

        if (removed[x]) {
            continue;
        }
        removed[x] = true;

        int l = leftNode[x];
        int r = rightNode[x];
        rightNode[l] = r;
        leftNode[r] = l;
    }

    for (int i = rightNode[0]; i != 0; i = rightNode[i]) {
        cout << i << " ";
    }

    return 0;
}
```
