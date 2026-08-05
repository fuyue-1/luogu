# T. 验证排序序列

## 核心思路

用栈模拟排序或出栈过程。按照目标序列依次检查，能入栈就入栈，栈顶等于当前目标值时就弹出。

## 实现要点

- 用一个指针表示当前要匹配的目标元素。
- 按顺序把元素压入栈。
- 每次压栈后，尽可能弹出与目标序列匹配的元素。
- 最后如果所有目标元素都能匹配，说明序列合法。

## 复杂度

时间复杂度：O(n)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool check(const vector<int>& in, const vector<int>& out) {
    stack<int> st;
    int j = 0;

    for (int x : in) {
        st.push(x);
        while (!st.empty() && j < (int)out.size() && st.top() == out[j]) {
            st.pop();
            j++;
        }
    }

    return j == (int)out.size();
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        vector<int> in(n), out(n);
        for (int i = 0; i < n; i++) {
            cin >> in[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> out[i];
        }

        cout << (check(in, out) ? "Yes" : "No") << endl;
    }

    return 0;
}
```
