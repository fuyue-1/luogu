# H. 质数筛

## 核心思路

使用埃氏筛或欧拉筛预处理一定范围内的质数，再根据询问快速判断或输出结果。

## 实现要点

- 先建立 `isPrime` 数组。
- 质数筛从 2 开始处理。
- 1 不是质数，需要单独标记。
- 多次询问时，预处理一次即可。

## 复杂度

时间复杂度：O(n log log n)  
空间复杂度：O(n)

## 参考代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (isPrime(x)) {
            cout << x << " ";
        }
    }

    return 0;
}
```
