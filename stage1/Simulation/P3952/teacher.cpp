#include <iostream>
using namespace std;
const int maxn = 1e6+5;
int n,m;
string s;
int T;                          // 数据组数

int max_time  = 0;              // 当前程序实际的最大时间复杂度指数
bool err_flag = 0;              // 标记是否发现语法错误
int read_line_cnt = 0;          // 当前程序还剩多少行没读

struct my_sta {
    int a[maxn];    // 栈的底层数组
    int idx = 0;    // 栈顶指针(同时表示栈的大小)

    void clear() { idx = 0;}                // 清空栈
    void push(int v) { a[idx++] = v;}       // 压栈: 当前层总指数 = v
    void pop() {--idx;}                     // 弹栈: 当前循环结束
    int size() {return idx;}                // 栈中元素个数
    bool empty() { return idx == 0;}        // 判空
    int top() { return a[idx-1];}           // 取栈顶(当前嵌套深度的总指数)
    int atop() {
        if( empty() ) return 0;             // 空栈说明没有外层循环, 指数为 0
        return top();
    }
} sta;

int cnt;                        // 当前活着的变量个数
string bct[maxn];               // 活着的变量名列表

void push_str(const string &s ) {
    bct[cnt++] = s;             // 新变量加入"存活名单"
}
void pop_str() {
    cnt--;                      // 最内层循环结束, 对应变量"销毁"
}
bool find_str(const string & s) {
    // 遍历当前所有存活变量, 看名字 s 是否已被占用
    for(int i = 0;i < cnt ;++i )
    {
        if( bct[i] == s) return 1;  // 找到重复, 返回 true
    }
    return 0;                       // 没找到, 名字可用
}


bool with_n = 0;                // 小明声称的复杂度是否包含 n (O(n^w) 为 1, O(1) 为 0)
int _time;                      // 小明声称的指数 w (O(1) 时为 0)

void time_complex(){
    cin >> s;
    int l = s.length();
    with_n = 0;
    _time = 0;

    // 第一遍扫描: 看字符串里有没有字母 'n'
    for(int i =0; i < l;i++)
        if(s[i] == 'n') {
            with_n = 1;         // 说明是 O(n^w) 形式
            break;
        }

    // 第二遍扫描: 提取数字 (连续的), 就是指数 w
    for(int i =0; i < l;i++)
    {
        if( s[i] >='0' && s[i] <= '9' )
        {
            int t = s[i] - '0';
            _time *= 10;
            _time += t;
        }
    }
    // 如果输入是 O(1), 上面提取不到数字, _time 保持 0, with_n 也是 0
}


int get_n_number(const string & s) {
    if( s[0] == 'n') return -1;     // 特殊标记: 这个是 n, 不是数字
    int n = 0;
    for(int i = 0 ;i< s.length() ;i++) {
        n *=10;
        n += s[i] -'0';
    }
    return n;
}


void read_until_e() {
    int e_cnt = 1;              // 当前还有 e_cnt 层循环没配对
    string var ,x,y;
    while(1) {
        cin >> var;
        if( var == "E") {
            read_line_cnt--;    // 消耗一行
            if( e_cnt == 1) break;  // 正好配对到当前这层的 E
            e_cnt--;            // 是内层循环的 E
        }
        else { // 只可能是 for (F)
            cin >> var >> x >> y;
            read_line_cnt--;    // 消耗一行
            e_cnt++;            // 又嵌套了一层
        }
    }
}

void deal_f() {
    string var,s,t;
    cin >> var >> s >> t;       // 读入: 变量名, 起点, 终点

    int x = get_n_number(s);    // x: 起点对应的数值, -1 表示 n
    int y = get_n_number(t);    // y: 终点对应的数值, -1 表示 n

    // === 语法检查: 变量名是否与已存活的变量重复 ===
    bool _find = find_str(var);
    if( _find ) {
        err_flag = 1;           // 发现重复变量, 标记错误
    }

    // k = 当前外层循环贡献的总指数 (栈顶)
    int k = sta.atop();

    if( x == -1 && y == -1) {
        // === 情况1: n -> n ===
        // n 到 n, 只执行 1 次, 常数级别, 指数不增加
        push_str(var);          // 变量加入存活名单
        sta.push(k + 0);        // 总指数 = 外层指数 + 0
    }
    else if( x !=-1 && y != -1 ){ // === 情况2: 数字 -> 数字 ===
        push_str(var);
        sta.push(0 + k);        // 总指数不变
    }
    else { // === 情况3: 有一个是 n ===
        if( x == -1) { // === 情况3a: n -> 数字 ===
            read_until_e();     // 把对应的 F...E 全部读完
        }
        else{  // === 情况3b: 数字 -> n ===
            push_str(var);
            sta.push(1 + k);    // 总指数 = 外层指数 + 1
        }
    }
    // 更新当前程序的最大指数 (用于和声称的复杂度比较)
    max_time = max(max_time,sta.atop());
}

void deal_e() {
    if( sta.empty()) {
        // 栈已经空了, 却来了个 E -> F 和 E 不匹配 (语法错误①)
        err_flag = 1;
    } else {
        sta.pop();              // 弹出当前层复杂度指数
        pop_str();              // 销毁当前层变量
    }
}

void read_one_data() {
    cin >> n;
    read_line_cnt = n;          // 这个程序共有 n 行

    time_complex();             // 解析声称的复杂度 -> with_n, _time

    while( read_line_cnt > 0)   // 逐行处理
    {
        read_line_cnt--;
        cin >> s;
        if( s[0] == 'F') {
            deal_f();           // 进入循环
        }
        else if( s[0] == 'E') {
            deal_e();           // 退出循环
        }
    }

    // 处理完后, 如果栈非空 -> 有 F 没配对的 E, 语法错误①
    if( !sta.empty()) err_flag = 1;

    // === 输出结果 ===
    if( err_flag ) {
        cout << "ERR\n";        // 只要有语法错误, 不管复杂度对不对都输出 ERR
    }
    else {
        // 比较实际复杂度 max_time 和声称复杂度 _time
        if( max_time ==  0 && with_n == 0) {
            // 实际 O(1), 声称 O(1) -> Yes
            std::cout << "Yes"<< "\n";
        }
        else if( max_time != 0 && with_n == 1 ) {
            // 实际含 n, 声称也含 n, 比较指数是否相等
            if( max_time == _time )
                std::cout << "Yes"<< "\n";
            else
                std::cout << "No"<< "\n";
        }
        else {
            // 一个 O(1) 一个 O(n^w), 肯定不一样
            std::cout << "No"<< "\n";
        }
    }
}

int main (int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        // 每组数据前, 重置所有全局状态!
        sta.clear();            // 清空栈
        max_time = 0;           // 最大指数归零
        err_flag = 0;           // 错误标记归零
        cnt=0;                  // 存活变量数归零
        read_line_cnt = 0;      // 剩余行数归零
        read_one_data();
    }

    return 0;
}