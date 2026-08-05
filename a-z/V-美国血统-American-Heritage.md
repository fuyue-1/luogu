# V. 美国血统 American Heritage

## 核心思路

已知二叉树的前序遍历和中序遍历，可以递归还原二叉树，并输出后序遍历。

## 实现要点

- 前序遍历的第一个字符是当前子树根节点。
- 在中序遍历中找到根节点，左边是左子树，右边是右子树。
- 递归处理左子树和右子树。
- 后序遍历输出顺序是：左子树、右子树、根节点。

## 复杂度

时间复杂度：O(n^2)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
#include <string>
using namespace std;

void buildPostorder(string preorder, string inorder) {
    if (preorder.empty()) {
        return;
    }

    char root = preorder[0];
    int pos = inorder.find(root);

    string leftIn = inorder.substr(0, pos);
    string rightIn = inorder.substr(pos + 1);

    string leftPre = preorder.substr(1, leftIn.size());
    string rightPre = preorder.substr(1 + leftIn.size());

    buildPostorder(leftPre, leftIn);
    buildPostorder(rightPre, rightIn);
    cout << root;
}

int main() {
    string inorder, preorder;
    cin >> inorder >> preorder;

    buildPostorder(preorder, inorder);
    cout << endl;

    return 0;
}
```
