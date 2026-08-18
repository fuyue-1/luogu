# luogu 50道基础题
- [luogu 50道基础题](#luogu-50道基础题)
- [语法基础题](#语法基础题)
- [B题 上学迟到【向上取整公式】](#b题-上学迟到向上取整公式)
- [D 10进制数转化【除每一位然后reverse】](#d-10进制数转化除每一位然后reverse)
- [E. x 进制转 10 进制](#e-x-进制转-10-进制)
    - [核心思路](#核心思路)
    - [核心代码](#核心代码)
- [H 质数筛选【1不是质数，i\*i\<=x】](#h-质数筛选1不是质数iix)
    - [参考代码](#参考代码)
- [I 旗鼓相当的对手【结构体】](#i-旗鼓相当的对手结构体)
- [J 数字反转](#j-数字反转)
- [K.生日相遇问题](#k生日相遇问题)
- [L.文字处理软件](#l文字处理软件)
- [M.扫雷游戏](#m扫雷游戏)
- [N.显示屏](#n显示屏)
- [O.外星密码【递归】](#o外星密码递归)
- [P.2 的幂次展开【递归】](#p2-的幂次展开递归)
- [Q.蛇形方针【方向数组】](#q蛇形方针方向数组)
- [R.天干地支](#r天干地支)
- [S.后缀表达式](#s后缀表达式)
- [T.验证排序序列](#t验证排序序列)
- [U.队列安排](#u队列安排)
- [V.美国血统](#v美国血统)
- [W.最大公约数和最小公倍数问题【gcd】](#w最大公约数和最小公倍数问题gcd)
- [X.查找【题目规定下标从1开始，原数组有序-\>二分查找】](#x查找题目规定下标从1开始原数组有序-二分查找)
  - [参考代码](#参考代码-1)
- [Y.a-b数对【题目要求long long类型】](#ya-b数对题目要求long-long类型)
- [Z.砍树](#z砍树)
- [数据结构方面题库](#数据结构方面题库)
- [A.凌乱的yyy / 线段覆盖](#a凌乱的yyy--线段覆盖)
- [B.](#b)
# 语法基础题
# B题 上学迟到【向上取整公式】
```cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int s, v;
    cin >> s >> v;

    int travel = (s + v - 1) / v;
    int start = 8 * 60 - travel - 10;

    if (start < 0) {
        start += 24 * 60;
    }

    int hour = start / 60;
    int minute = start % 60;

    cout << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << minute << endl;

    return 0;
}
```
头文件是iomanip
setw(2)设置紧跟其后的一次输出宽度为2
不足位数默认填充是空格，超出位数可以全部显示
setfill('0') 全局生效，位数不足时填充字符是'0'
# D 10进制数转化【除每一位然后reverse】
把十进制整数 `n` 不断对目标进制 `x` 取余，得到的余数就是从低位到高位的每一位；然后再把 `n` 更新为 `n / x`，直到 `n` 变为 `0`。

由于先得到的是最低位，最后需要把结果反转输出。

当余数大于等于 `10` 时，用大写字母表示
**参考代码：**

```cpp
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    string ans;
    while (n > 0) {
        int r = n % x;
        if (r < 10) {
            ans.push_back(char('0' + r));
        } else {
            ans.push_back(char('A' + r - 10));
        }
        n /= x;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
```
reverse函数需要头文件algorithm,可用于string和vector
# E. x 进制转 10 进制

### 核心思路

从高位到低位扫描字符串 `S`，用秦九韶算法（逐步累乘）把 `x` 进制数转换成十进制：

```text
ans = ans * x + 当前位的数值
```
### 核心代码

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x;
    string s;
    cin >> x >> s;

    long long ans = 0;
    for (char c : s) {
        int d;
        if (c >= '0' && c <= '9') {
            d = c - '0';
        } else {
            d = c - 'A' + 10;
        }
        ans = ans * x + d;
    }

    cout << ans << endl;
    return 0;
}
```
# H 质数筛选【1不是质数，i*i<=x】
- 先建立 `isPrime` 数组。
- 质数筛从 2 开始处理。


### 参考代码

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
# I 旗鼓相当的对手【结构体】
```cpp
struct Student {
    string name;
    int chinese;
    int math;
    int english;
    int total;
};
Student a[1005];
```
# J 数字反转
实数是**小数，分数，百分数，整数**
看清逻辑，实则只有2种写法，一个是反转整数部分，一个是小数部分
区别是删掉前置的0，还是后置的0
```
s.find('.')
作用：在字符串 s 里面查找字符 .
如果找到：返回小数点所在的下标（int）
如果找不到：返回常量 string::npos

string::npos 是 string 类内置静态常量，表示查找失败。
本质是一个很大的无符号整数（一般为 4294967295）。
```
```cpp
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string reverseInt(string a){
    int pos=0;
    reverse(a.begin(),a.end());
    while(pos+1<(int)a.size() && a[pos]=='0'){
        pos++;
    }
    return a.substr(pos);
}
string reverseDeci(string b){
    reverse(b.begin(),b.end());
    while(b.size()>1 &&b.back()=='0'){
        b.pop_back();
    }
    return b;
}
int main(){
    string s;
    cin>>s;
    if(s.back()=='%'){
        s.pop_back();
        cout<<reverseInt(s)<<'%'<<endl;
    }else if(s.find('.')!=string::npos){
        int p=s.find('.');
        string le=s.substr(0,p);
        string ri=s.substr(p+1);
        cout<<reverseInt(le)<<'.'<<reverseDeci(ri)<<endl;
    }else if(s.find('/')!=string::npos){
        int p=s.find('/');
        string le=s.substr(0,p);
        string ri=s.substr(p+1);
        cout<<reverseInt(le)<<'/'<<reverseInt(ri)<<endl;
    }else cout<<reverseInt(s)<<endl;
    
    return 0;
}
```
# K.生日相遇问题
```
闰年是366天，2月29天
int week1 = (firstWeekday + day1 - 1) % 7;
```
```cpp
#include <iostream>
using namespace std;
//判断该年份是闰年还是平年
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
//算生日是该年份的 第几天
int getDayOfYear(int month, int day, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(year)) {
        days[1] = 29;
    }

    if (month == 2 && day == 29 && !isLeap(year)) {
        day = 28;
    }

    int result = 0;
    for (int i = 0; i < month - 1; i++) {
        result += days[i];
    }
    return result + day;
}

int main() {
    int m, d1, n, d2, k;
    cin >> m >> d1 >> n >> d2 >> k;
    
    int firstWeekday = 3; // 2025 年 1 月 1 日是星期三
    bool found = false;

    for (int year = 2025; year < 2025 + k; year++) {
        int day1 = getDayOfYear(m, d1, year);
        int day2 = getDayOfYear(n, d2, year);

        //算生日是周几
        int week1 = (firstWeekday + day1 - 1) % 7;
        int week2 = (firstWeekday + day2 - 1) % 7;

        if (week1 == week2) {
            cout << year << endl;
            found = true;
        }
        //// 用2025年的总天数(365/366)，推算2026年元旦的星期
        firstWeekday = (firstWeekday + (isLeap(year) ? 366 : 365)) % 7;
    }

    if (!found) {
        cout << "No Answer" << endl;
    }

    return 0;
}
```
# L.文字处理软件
**注意的是需要s改变，后续的s依靠前面的s的基础**
**拼接，截取，插入，查找**
```cpp
    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            string t;
            cin >> t;
            s += t;
            cout << s << endl;
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            s = s.substr(a, b);
            cout << s << endl;
        } else if (op == 3) {
            int a;
            string t;
            cin >> a >> t;
            s.insert(a, t);
            cout << s << endl;
        } else if (op == 4) {
            string t;
            cin >> t;
            int pos = s.find(t);
            cout << pos << endl;
        }
    }
```
# M.扫雷游戏
重点是输出一行要换行，否则不通过，注意题目中**输出格式**
```cpp
int main() {
    int n, m;
    cin >> n >> m;

    char a[105][105];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') {
                cout << '*';
                continue;
            }

            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '*') {
                    cnt++;
                }
            }
            cout << cnt;
        }
        cout << endl;
    }

    return 0;
}
```
# N.显示屏
重点是理解显示逻辑，输出所有数字的第n行，再接着输入下一行
```cpp
int main() {
    int n;
    string s;
    cin >> n >> s;

    string digit[10][5] = {
        {"XXX", "X.X", "X.X", "X.X", "XXX"},
        {"..X", "..X", "..X", "..X", "..X"},
        {"XXX", "..X", "XXX", "X..", "XXX"},
        {"XXX", "..X", "XXX", "..X", "XXX"},
        {"X.X", "X.X", "XXX", "..X", "..X"},
        {"XXX", "X..", "XXX", "..X", "XXX"},
        {"XXX", "X..", "XXX", "X.X", "XXX"},
        {"XXX", "..X", "..X", "..X", "..X"},
        {"XXX", "X.X", "XXX", "X.X", "XXX"},
        {"XXX", "X.X", "XXX", "..X", "XXX"}
    };
    /*
    XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
    X.X...X...X...X.X.X.X...X.....X.X.X.X.X
    X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
    X.X...X.X.....X...X...X.X.X...X.X.X...X
    XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX

    */
    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            cout << digit[s[i] - '0'][row];
            if (i != n - 1) {
                cout << ".";
            }
        }
        cout << endl;
    }

    return 0;
}
```

# O.外星密码【递归】
- 从左到右扫描字符串。
- 遇到普通字符，直接加入当前答案。
- 遇到 `[` 后，先跳过 `[`。
- 读取 `[` 后面的数字，得到重复次数。
- **递归**处理括号内部。
- 遇到 `]` 表示当前递归层结束。
- 返回解析出的字符串给上一层继续拼接。
  
**判断当前是否是数字isdigit(a)，即a是不是数字**
注意pos++，可以跳过 ' [ ' , ' ]'
```cpp
string s;
int pos = 0;

string decode() {
    string result;

    while (pos < (int)s.size() && s[pos] != ']') {
        if (s[pos] == '[') {
            pos++; // 跳过 [

            int times = 0;
            while (pos < (int)s.size() && isdigit(s[pos])) {
                times = times * 10 + s[pos] - '0';
                pos++;
            }

            string inner = decode();
            pos++; // 跳过 ]

            while (times--) {
                result += inner;
            }
        } else {
            result += s[pos];
            pos++;
        }
    }

    return result;
}
```
# P.2 的幂次展开【递归】
逐位置看 n 的二进制第 i 位是不是 1
格式的要求：
1. $2^0$ →输出 `2(0)`
2. $2^1$ →输出 `2`
3. $2^k\ (k>1)$ →输出 `2(指数的表达式)`，指数 $k$ 自己也要递归拆解，调用`solve(i)`
```cpp
string solve(int n) {
    string result;

    for (int i = 15; i >= 0; i--) {
        //取出第i位
        if ((n >> i) & 1) {
            string term;
            if (i == 0) {
                term = "2(0)";
            } else if (i == 1) {
                term = "2";
            } else {
                term = "2(" + solve(i) + ")";
            }

            if (!result.empty()) {
                result += "+";
            }
            result += term;
        }
    }

    return result;
}
```
# Q.蛇形方针【方向数组】
- 用二维数组保存答案。
- 设置方向数组：右、下、左、上。
- 每填入一个数后，尝试走到下一个位置。
- 如果越界或已访问，则转向。
```cpp
int main() {
    int n;
    cin >> n;

    int a[15][15] = {};
    int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

    int x = 0, y = 0, dir = 0;
    for (int num = 1; num <= n * n; num++) {
        a[x][y] = num;

        int nx = x + d[dir][0];
        int ny = y + d[dir][1];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != 0) {
            //让 d 永远限制在 0、1、2、3 之间循环，不会超出 dir 数组下标
            dir = (dir + 1) % 4;
            nx = x + d[dir][0];
            ny = y + d[dir][1];
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
```
# R.天干地支
- 准备天干数组和地支数组。
- 选择题目给定的基准年份。
- 计算年份差，并分别对 10 和 12 取模。
- 注意负数取模时要转成非负结果。
  
```cpp
int main() {
    int year;
    cin >> year;

    string stem[] = {"jia", "yi", "bing", "ding", "wu",
                     "ji", "geng", "xin", "ren", "gui"};
    string branch[] = {"zi", "chou", "yin", "mao", "chen", "si",
                       "wu", "wei", "shen", "you", "xu", "hai"};

    //任何整数 %12，C++ 得到结果范围一定是：[-11 , 11]
    int stemIndex = (6 + (year - 2020) % 10 + 10) % 10;
    int branchIndex = (0 + (year - 2020) % 12 + 12) % 12;

    cout << stem[stemIndex] << branch[branchIndex] << endl;
    return 0;
}
```
# S.后缀表达式
**注意这个题 是后出的数字是先进来的，作为被除数和被减数**
- 数字可能不止一位，要完整读入。
- 遇到运算符时，注意两个操作数的顺序。
- 对于减法和除法，先弹出的数是右操作数。
- 表达式结束后，栈顶就是最终答案。
```cpp
int main() {
    stack<int> st;
    char ch;

    while (cin >> ch && ch != '@') {
        if (ch >= '0' && ch <= '9') {
            int num = ch - '0';
            while (cin >> ch && ch >= '0' && ch <= '9') {
                num = num * 10 + ch - '0';
            }
            st.push(num);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            //后进来的在顶端
            //注意别弄错顺序了
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (ch == '+') {
                st.push(a + b);
            } else if (ch == '-') {
                st.push(a - b);
            } else if (ch == '*') {
                st.push(a * b);
            } else {
                st.push(a / b);
            }
        }
    }

    cout << st.top() << endl;
    return 0;
}
```
# T.验证排序序列
- 用一个指针表示当前要匹配的目标元素。
- 按顺序把元素压入栈。
- 每次压栈后，尽可能弹出与目标序列匹配的元素。
- 最后如果所有目标元素都能匹配，说明序列合法。
```cpp
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
# U.队列安排
**难点在于用两个数组来模拟双向链表**
维护每个人左右两边的人，相当于用数组模拟双向链表。插入时修改相邻关系，删除时把该节点从链表中断开。
- `left[i]` 表示 i 左边的人，`right[i]` 表示 i 右边的人。
- 插入到某人左边或右边时，要同时修改前后节点的指针。
- 删除某人时，如果已经删除过就跳过。
- 最后从队头开始沿 `right` 输出队列。
```cpp
/*
使用0 作为虚拟哨兵，构建环形双向链表；真实节点 1~n。
逐个插入节点：输入 k、p，把新节点插到 k 左边 / 右边。
m 次删除：删除指定编号节点，重复删除直接跳过。
从哨兵往后遍历链表，输出剩下所有节点编号。
*/
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
        //removed[x]判断：如果已经删过，直接跳过，防止重复删除。标记为已删除。
        if (removed[x]) {
            continue;
        }
        removed[x] = true;

        int l = leftNode[x];
        int r = rightNode[x];
        rightNode[l] = r;
        leftNode[r] = l;
    }
    //初始化：int i = rightNode[0];
    //循环条件：i != 0;
    //每次循环结束执行：i = rightNode[i];

    // rightNode[x]存 x 的后继，也就是 x 的下一个节点编号
    for (int i = rightNode[0]; i != 0; i = rightNode[i]) {
        cout << i << " ";
    }

    return 0;
}
```
# V.美国血统
- 前序遍历的第一个字符是当前子树根节点。
- 在中序遍历中找到根节点，左边是左子树，右边是右子树。
- 递归处理左子树和右子树。
- 后序遍历输出顺序是：左子树、右子树、根节点。
```cpp
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
# W.最大公约数和最小公倍数问题【gcd】
若两个数的最大公约数为 `x`，最小公倍数为 `y`，则这两个数可以写成 `x * a` 和 `x * b`。此时需要满足：

```text
a * b = y / x
gcd(a, b) = 1
```
- 如果 `y` 不能被 `x` 整除，则没有答案。
- 枚举 `a`，令 `b = (y / x) / a`。
- 只有 `a * b = y / x` 且 `gcd(a, b) = 1` 时才计数。
- 注意有序数对和无序数对的统计方式要按题目要求处理。
```cpp
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    long long x, y;
    cin >> x >> y;

    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long n = y / x;
    long long ans = 0;

    for (long long a = 1; a * a <= n; a++) {
        if (n % a != 0) {
            continue;
        }

        long long b = n / a;
        if (gcd(a, b) == 1) {
            ans += (a == b ? 1 : 2);
        }
    }

    cout << ans << endl;
    return 0;
}
```
# X.查找【题目规定下标从1开始，原数组有序->二分查找】
**要求输出这个数字在序列中第一次出现的编号**
- 二分时不要只判断是否存在，还要继续向左收缩，寻找第一次出现的位置。
- 找不到时按题目要求输出指定值，常见为 `-1`。
- 注意输出位置是从 0 开始还是从 1 开始。

时间复杂度：O(q log n)  
空间复杂度：O(1)

## 参考代码

```cpp
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (m--) {
        int x;
        cin >> x;

        int left = 1;
        int right = n;
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] >= x) {
                if (a[mid] == x) {
                    ans = mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << ans << " ";
    }

    return 0;
}
```
# Y.a-b数对【题目要求long long类型】
**typedef long long LL;**

题目要求统计满足 `A - B = C` 的数对数量。可以将式子转化为查找 `A - C` 是否出现过。


- 使用哈希表统计每个数出现的次数。
- 遍历每个数 `A`，答案加上 `A - C` 的出现次数。
- 注意重复数字会产生多个数对，不能只判断是否存在。


时间复杂度：O(n) 或 O(n log n)  
空间复杂度：O(n)

```cpp
int main() {
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> a(n);
    unordered_map<long long, long long> cnt;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[a[i] - c];
    }

    cout << ans << endl;
    return 0;
}
```

# Z.砍树
砍树高度越低，得到的木材越多；砍树高度越高，得到的木材越少。因此答案具有单调性，可以二分砍树高度。


- 二分范围为 `0` 到最高树高。
- 对于一个高度 `mid`，计算所有树超过 `mid` 的部分总和。
- 如果得到的木材不少于目标值，说明高度还可以更高。
- 否则高度需要降低。
- 最后输出满足条件的最大高度。


时间复杂度：O(n log H)  
空间复杂度：O(1)


```cpp
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
            //max(0,tree[i]-mid),0是 long long类型的
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
# 数据结构方面题库
# A.凌乱的yyy / 线段覆盖
**重点在于思维逻辑，排序排的是右边界，比较last和当前的左边界**
这是经典的区间选择问题：给出若干线段，要求选出尽量多的互不相交线段。

贪心策略是：按照线段右端点从小到大排序，每次选择当前能选的、结束最早的线段。这样可以给后面的线段留下尽可能大的空间。

**实现要点**

- 将每条线段存成 `(l, r)`。
- 按 `r` 从小到大排序。
- 维护当前已经选择线段的结束位置 `last`。
- 如果当前线段左端点 `>= last`，就可以选择它。
  
```cpp
struct Node {
    int l, r;
};

int main() {
    int n;
    cin >> n;

    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end(), [](Node x, Node y) {
        return x.r < y.r;
    });

    int ans = 0;
    int last = -1;

    for (auto x : a) {
        if (x.l >= last) {
            ans++;
            last = x.r;
        }
    }

    cout << ans << endl;
    return 0;
}
```
# B.