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
- [B. 合并果子【小根堆，priority\_queue】](#b-合并果子小根堆priority_queue)
- [C. 语文成绩【差分数组】](#c-语文成绩差分数组)
- [D. 地毯【二维差分】](#d-地毯二维差分)
- [E. 最大加权矩形【降维】](#e-最大加权矩形降维)
- [F. 木材加工【答案具有单调性，二分】](#f-木材加工答案具有单调性二分)
- [G. 跳石头【答案二分+贪心】【\*\*】](#g-跳石头答案二分贪心)
- [H.狠狠地切割【unordered\_set 哈希集合】](#h狠狠地切割unordered_set-哈希集合)
- [I. 单调队列 / 滑动窗口【数组实现 单调递增/递减队列】【\*\*】](#i-单调队列--滑动窗口数组实现-单调递增递减队列)
- [J. 海港【队列】](#j-海港队列)
- [K. 亲戚【并查集】](#k-亲戚并查集)
- [L. 修复公路【Kruskal + 并查集】【\*\*】](#l-修复公路kruskal--并查集)
- [M. 选数【dfs，剪枝】](#m-选数dfs剪枝)
- [N. 迷宫【 dfs，二维dir\[4\]\[4\] 】](#n-迷宫-dfs二维dir44-)
- [O. 马的遍历【BFS+队列】](#o-马的遍历bfs队列)
- [P. Corn Maze S【bfs,最短路】](#p-corn-maze-sbfs最短路)
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
# B. 合并果子【小根堆，priority_queue】

每次合并两堆果子，消耗为两堆重量之和。为了让总代价最小，每次都应该选择当前最小的两堆合并。

这就是哈夫曼合并问题，可以用小根堆维护所有果子堆。

- 将所有果子重量放入小根堆。
- 每次取出最小的两个数 `x` 和 `y`。
- 答案加上 `x + y`。
- 将合并后的新堆 `x + y` 放回堆中。
- 直到堆中只剩一堆。
```cpp
//大根堆，top()拿到最大数
priority_queue<int> q1;

//小根堆，top()拿到最小数
priority_queue<int, vector<int>, greater<int>> q2;
```

```cpp
int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    while (q.size() > 1) {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();

        ans += x + y;
        q.push(x + y);
    }

    cout << ans << endl;
    return 0;
}
```
# C. 语文成绩【差分数组】

这类题通常是区间加法后查询最终最小值，可以用**差分数组**优化。

设原数组为 `a`，差分数组为 `d`：

```text
d[i] = a[i] - a[i - 1]
```

如果要给区间 `[l, r]` 全部加上 `x`，只需要：

```text
d[l] += x
d[r + 1] -= x
```

最后对差分数组求前缀和，就能还原修改后的成绩。

**要点**

- 读入原成绩时建立差分数组。
- 每次区间修改只改两个位置。
- 所有操作结束后求前缀和。
- 扫描得到最终最小成绩。
```cpp
//暴力写法会超时
int main(){
    int n,p; cin>>n>>p;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    while(p--){
        int x,y,z;
        cin>>x>>y>>z;
        for(int i=x;i<=y;i++) a[i]=min(100,a[i]+z);
    }
    cout<<*min_element(a.begin()+1,a.end())<<endl;
    return 0;
}
```
```cpp 
//正确写法，重点就是利用  差分 来避免暴力解法
const int N = 5000005;
long long d[N];
int main() {
    int n, m;
    cin >> n >> m;

    long long last = 0;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        d[i] = x - last;
        last = x;
    }

    while (m--) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }
    //求前缀和
    long long cur = 0;
    long long ans = 1e18;
    for (int i = 1; i <= n; i++) {
        cur += d[i];
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
```
# D. 地毯【二维差分】
给出一个 `n * n` 的网格和若干次铺地毯操作，每次覆盖一个矩形区域，要求输出每个位置被覆盖的次数。
可以使用**二维差分**。对矩形 `(x1, y1)` 到 `(x2, y2)` 加 `1`：
```text
d[x1][y1] += 1
d[x2 + 1][y1] -= 1
d[x1][y2 + 1] -= 1
d[x2 + 1][y2 + 1] += 1
```

最后对二维差分求前缀和，即可得到每个点的覆盖次数。

- 建立二维差分数组。
- 每次矩形修改**只改四个角**。
- 最后用二维前缀和还原答案。

```cpp
const int N = 1005;
int d[N][N];
int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1]++;
        d[x2 + 1][y1]--;
        d[x1][y2 + 1]--;
        d[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (j > 1) {
                cout << ' ';
            }
            cout << d[i][j];
        }
        cout << endl;
    }
    return 0;
}
```
# E. 最大加权矩形【降维】
求矩阵中权值和最大的子矩形，可以枚举子矩形的上下边界，把二维问题压缩成一维最大子段和问题。**固定上下两行，把每一列纵向加起来得到一维数组。一维数组的连续区间，对应原矩阵的一个矩形**

固定上边界 `top` 和下边界 `bottom` 后，每一列在这两行之间的和可以看作一个一维数组。此时问题变成求这个数组的最大连续子段和。

- 枚举上边界 `top`。
- 用数组 `col[j]` 维护从 `top` 到当前 `bottom` 第 `j` 列的和。
- 每增加一行 `bottom`，更新 `col`。
- 对 `col` 做一次最大子段和。

```cpp
const int N = 105;
int a[N][N], col[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int ans = -1e9;

    for (int top = 1; top <= n; top++) {
        //换新的上边，列和全部清零
        for (int j = 1; j <= n; j++) {
            col[j] = 0;
        }
        //bottom从top往下一行一行增加
        for (int bottom = top; bottom <= n; bottom++) {
            //把bottom这一行加到col数组
            for (int j = 1; j <= n; j++) {
                col[j] += a[bottom][j];
            }

            int cur = col[1];
            ans = max(ans, cur);
            for (int j = 2; j <= n; j++) {
                //二选一：要么接上前面一段，要么从当前重新开始
                cur = max(col[j], cur + col[j]);
                ans = max(ans, cur);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
```
# F. 木材加工【答案具有单调性，二分】
给若干根木材，要切出至少 `k` 段长度相同的小木段，长度尽可能大。
**答案具有单调性**：如果长度 `x` 可以切出至少 `k` 段，那么更短的长度也一定可以；如果长度 `x` 不可以，那么更长的长度也不可以。
**可行的答案分布：[可以，可以，可以，不可以，不可以]
我们要找最后那个可行的数字，这就是二分答案干的活。
因此可以二分答案。**

- 二分小木段长度 `mid`。
- 统计所有木材能切出多少段 `len[i] / mid`。
- 如果总段数不少于 `k`，说明 `mid` 可行，尝试更大。
- 否则尝试更小。

```cpp
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int l = 1, r = mx, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        long long cnt = 0;

        for (int x : a) {
            cnt += x / mid;
        }

        if (cnt >= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
```
# G. 跳石头【答案二分+贪心】【**】
**最多搬走 m 块石头，要让剩下石头之间最短的间隔，尽可能大**
答案有单调性：如果最小距离 `x` 可以做到，那么更小的距离也可以做到；如果 `x` 做不到，那么更大的距离也做不到。
因此**二分**最小距离。

**贪心**：（挪走当前石头比挪走上一个石头好，挪走当前的可以让相邻的2个都获得大空间）需要搬走的石头总数最少。
从左到右，一发现距离不够，立刻把当前石头扔掉，就是**局部最优**。

- 把起点 `0` 和终点 `L` 也看作石头。
- 二分答案 `mid`。
- 从左到右**贪心检查**：如果当前石头到上一块保留石头的距离小于 `mid`，就必须移走当前石头。
- 统计需要移走的石头数是否 `<= m`。

```cpp
//循环会跑到i = n+1，也就是跑到终点。
//如果不写 a[n+1]=L，循环只会遍历河里真实石头，不会检查最后一块石头到对岸终点的距离！
int main() {
    int L, n, m;
    cin >> L >> n >> m;

    vector<int> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = L;

    int l = 1, r = L, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int last = 0;
        int removed = 0;
        //循环结束，removed就是要实现 “全部间隔≥mid”，一共需要搬走多少石头。
        for (int i = 1; i <= n + 1; i++) {
            // 当前石头和上一块保留石头距离小于mid，不满足条件，这块石头必须搬走
            if (a[i] - a[last] < mid) {
                removed++;
            } else {
                //距离够，这块石头留下，更新last
                last = i;
            }
        }

        if (removed <= m) {
            ans = mid;
            l = mid + 1;//尝试看看能不能找到更大的距离
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
```
# H.狠狠地切割【unordered_set 哈希集合】

给定一个序列 `a` 和一个集合 `b`。如果 `a[i]` 出现在集合 `b` 中，那么位置 `i` 就是切割点，需要把这个位置的数删除，并把左右两边分开。

最后要求的是删除所有切割点后，还剩下多少个非空连续片段。

所以可以把问题理解成：统计序列 `a` 中有多少段**连续的“非切割点”**。

遍历序列时：
如果当前数是切割点，说明当前片段结束。
如果当前数不是切割点，并且前一个位置不是片段中，那么开启一个新片段，答案加一。

- 用**unordered_set**保存所有切割数字，方便 `O(1)` 判断。
- 由于输入顺序是先给序列 `a`，再给集合 `b`，所以需要先保存序列 `a`。
- 用布尔变量 `inSegment` 表示当前是否处在一个非空片段中。
- 遇到切割点时令 `inSegment = false`。
- 遇到非切割点且 `inSegment == false` 时，说明新片段开始。

```cpp
int main() {
    //本题输入规模较大，建议考虑使用较快的读入读出方式。
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
# I. 单调队列 / 滑动窗口【数组实现 单调递增/递减队列】【**】
给定长度为 `n` 的序列，求每个长度为 `k` 的连续窗口中的最小值和最大值。

可以用单调队列维护窗口内可能成为答案的元素下标。

- 求最小值时，队列中元素值保持单调递增。
- 求最大值时，队列中元素值保持单调递减。

队首始终是当前窗口的最优值。

- 队列中存**下标**，不直接存值。
- 每次加入新元素前，弹出队尾中不可能成为答案的元素。
- 如果队首下标已经滑出窗口，就弹出队首。
- 当 `i >= k` 时输出当前窗口答案。
**这个题目注意下标 边界取不取等于，下标从0开始注意是'i>=k-1'**
```cpp
const int N = 1000005;

int a[N], q[N];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //初始化队列：head队首，tail队尾；tail<head代表队列为空
    int head = 1, tail = 0;

    for (int i = 1; i <= n; i++) {
        // ① 弹出队首：队首下标已经滑出窗口范围 [i‑k+1 , i]
        // i‑k 是窗口左边界的前一个位置；下标 ≤ i‑k 代表不在窗口里
        while (head <= tail && q[head] <= i - k) {
            head++;
        }
        // ②维护单调递增：队尾元素的值 ≥ 当前a[i]，队尾永远不可能成为后面窗口的最小值，直接删掉
        while (head <= tail && a[q[tail]] >= a[i]) {
            tail--;
        }
        // ③把当前下标i加入队尾
        q[++tail] = i;
        // ④i>=k，窗口凑齐k个元素，队首就是当前窗口最小值，输出
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
# J. 海港【队列】
要求统计最近 `86400` 秒内到达海港的乘客来自多少个不同国家。

可以用队列维护当前时间窗口内的所有乘客，同时用计数数组记录每个国家当前在窗口内有多少人。

每读入一艘船，就把船上所有乘客加入队列；然后弹出所有时间过期的乘客；最后统计当前仍在窗口内的国家数量。

- 队列中保存 `(到达时间, 国家)`。
- `cnt[country]` 表示当前窗口内该国家人数。
- 新国家人数从 `0` 变成 `1` 时，不同国家数加一。
- 国家人数从 `1` 变成 `0` 时，不同国家数减一。
```cpp
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
# K. 亲戚【并查集】
判断两个人是否属于同一个亲戚关系集合，可以使用**并查集**。
每给出一对亲戚关系，就把两个人所在集合合并。查询时判断两个人的祖先是否相同即可。
```
并查集两件事：
1.遇到关系就合并集合；
2.查询就找两个人的根，根相同就是亲戚。
```
- `fa[x]` 表示 `x` 的父节点。
- `find(x)` 查找集合代表元，并进行路径压缩。
- `merge(x, y)` 合并两个集合。
- 查询时比较 `find(x)` 和 `find(y)`。
  
**find是带路径压缩的查找函数，是并查集的核心，干两件事：1.找到 x 所在集合的根节点（祖先）2.路径压缩：把一路上的点直接指向根，加快后续查询速度**
```cpp
const int N = 5005;
int fa[N];

int find(int x) {
    //如果 fa[x]==x，说明 x 就是根，直接返回 x。
    if (fa[x] == x) {
        return x;
    }
    //递归去找父节点fa[x]的根；
    return fa[x] = find(fa[x]);
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        fa[find(x)] = find(y);
    }

    while (p--) {
        int x, y;
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes" : "No") << endl;
    }

    return 0;
}
```
# L. 修复公路【Kruskal + 并查集】【**】
每条公路有修复时间，要求找到最早的时间，使所有村庄连通。
**Kruskal 最小生成树：把边按代价从小到大拿，用并查集避免环。**
可以按时间从小到大排序道路，然后用并查集逐条合并。如果某一时刻连通块数量变成 `1`，说明所有村庄已经连通，这个时间就是答案。

- 按道路修复时间**排序**。
- 初始有 `n` 个连通块。
- 每成功合并两个不同集合，连通块数量减一。
- **连通块数量为 `1` 时输出当前时间**。
- 如果最后仍未连通，输出 `-1`。

```cpp
struct Edge {
    int x, y, t;
};

const int N = 1005;
int fa[N];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> e(m);
    for (int i = 0; i < m; i++) {
        cin >> e[i].x >> e[i].y >> e[i].t;
    }

    sort(e.begin(), e.end(), [](Edge a, Edge b) {
        return a.t < b.t;
    });

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    int cnt = n;
    for (auto edge : e) {
        int fx = find(edge.x);
        int fy = find(edge.y);
        if (fx != fy) {
            fa[fx] = fy;
            cnt--;
            if (cnt == 1) {
                cout << edge.t << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
``` 

# M. 选数【dfs，剪枝】
从 `n` 个数中选出 `k` 个数，如果它们的和是素数，就计入答案。

因为 `n` 通常较小，可以用 DFS 枚举所有选法。递归时记录当前选到的位置、已经选了几个数、当前和。

**要点**

- DFS 参数：当前位置 `idx`、已选数量 `cnt`、当前和 `sum`。
- 如果 `cnt == k`，判断 `sum` 是否为素数。
- 每次选择一个比上次下标更大的数，避免重复组合。
```cpp
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
# N. 迷宫【 dfs，二维dir[4][4] 】
**注意全局中不能定义y1，是关键字**
题目要求统计从起点走到终点的方案数，每个格子最多经过一次，并且不能走到障碍物上。求所有可行路径数量，所以用 DFS 回溯枚举路径。
**要点**
- 用 `blocked` 标记障碍物。
- 用 `vis` 标记当前路径中已经走过的位置。
- DFS 每次向四个方向扩展。
- 走到终点时答案加一。
- 回溯时要取消当前位置的访问标记，方便其他路径继续使用。
```cpp
const int N = 10;

bool blocked[N][N];
bool vis[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, t;
int sx, sy, fx, fy;
int ans = 0;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }
        if (blocked[nx][ny] || vis[nx][ny]) {
            continue;
        }

        vis[nx][ny] = true;
        dfs(nx, ny);
        vis[nx][ny] = false;
    }
}

int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        blocked[x][y] = true;
    }

    vis[sx][sy] = true;
    dfs(sx, sy);
    cout << ans << endl;

    return 0;
}
```
# O. 马的遍历【BFS+队列】
**输入涉及到坐标要注意题目中坐标是从0开始还是从1开始**
马在棋盘上有 8 种跳法，每次跳一步。要求从起点出发，到达棋盘上每个位置的最少步数。（**象棋的马走“日” 字：横向走 2 格纵向走 1 格，或者横向走 1 格纵向走 2 格。全部合法跳法一共 8 种组合**）

因为每次移动代价相同，所以使用 BFS。第一次访问到某个格子时，得到的就是最短步数。（**BFS（广度优先搜索）天生适合求无权图最短路径，每一次跳跃代价都是 1，第一次访问到格子，就是最短步数。**）
- 初始化所有位置距离为 `-1`。
- 起点距离为 `0`。
- BFS 扩展 8 个方向。
- 没访问过且在棋盘内的位置入队。
```
BFS 核心原理：
队列里面的节点，是按照距离起点由近到远排序。
起点 (距离 0)→所有跳一步能到的格子 (距离 1)→跳两步到的格子 (距离 2)……
第一次到达某点，一定是最短路径，后面再到这个点的路径步数只会更长，直接舍弃。
```
```cpp
const int N = 405;
//dist[i][j]：记录起点到(i,j)最少步数。
int dist[N][N];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    //把起点坐标放进队列；
    //起点到自己步数是 0。
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            //BFS 特性：先走到的路径步数一定更短，所以不需要再次处理。
            if (dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //left：左对齐输出。
            cout << left << setw(5) << dist[i][j];
        }
        cout << endl;
    }

    return 0;
}
```
# P. Corn Maze S【bfs,最短路】
这是带传送门的迷宫最短路问题。

从起点出发，每次可以向四个方向走一步。如果走到一个大写字母传送门，就会立即传送到相同字母的另一个位置。

因为每次移动代价相同，所以使用 BFS。第一次到达终点时就是最短步数。

- 读入地图，记录起点 `@`、终点 `=`。
- 对每个大写字母记录两个传送门位置。
- BFS 扩展四个方向。
- 如果新位置是传送门，就跳到对应的另一个传送门。
- 传送完成后再判断目标位置是否已经访问过。

```cpp
const int N = 305;

char g[N][N];
int dist[N][N];
vector<pair<int, int>> portal[26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int n, m;
    cin >> n >> m;

    int sx = 0, sy = 0;
    int tx = 0, ty = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            dist[i][j] = -1;
            if (g[i][j] == '@') {
                sx = i, sy = j;
            } else if (g[i][j] == '=') {
                tx = i, ty = j;
            } else if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
                portal[g[i][j] - 'A'].push_back({i, j});
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (g[nx][ny] == '#') {
                continue;
            }

            if (g[nx][ny] >= 'A' && g[nx][ny] <= 'Z') {
                int id = g[nx][ny] - 'A';
                auto a = portal[id][0];
                auto b = portal[id][1];
                if (nx == a.first && ny == a.second) {
                    nx = b.first;
                    ny = b.second;
                } else {
                    nx = a.first;
                    ny = a.second;
                }
            }

            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[tx][ty] << endl;
    return 0;
}
```
