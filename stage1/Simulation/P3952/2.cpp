#include <iostream>

using namespace std;

const int maxn = 1e6+5;
int n,m;
string s;
int T;                          // 数据组数

int max_time  = 0;              // 当前程序实际的最大时间复杂度指数
bool err_flag = 0;              // 标记是否发现语法错误
int read_line_cnt = 0;          // 当前程序还剩多少行没读

/**
 * 【手工栈 my_sta】
 * 为什么用栈? 循环允许嵌套, 后进先出(F 是入栈, E 是出栈)
 * 栈中每个元素存储: "从外层到当前层, 累计贡献的 n 的指数"
 * 例如: 第一层贡献 1, 第二层贡献 1, 栈顶就是 2 (表示当前在 n^2 的循环内)
 */
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

/**
 * 【变量名池 bct】
 * 作用: 记录当前所有"活着"的变量名, 用于检测变量名重复
 * 规则: 进入一个 F 就把变量名加入数组, 遇到 E 就把当前层变量名移除
 * 为什么不直接 map/set? 题目数据量小(L<=100), 数组遍历就够用了
 */
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


bool with_n = 0;                // 小明复杂度         
int _time;

void time_complex(){
    cin >> s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]=='n'){
            with_n=1;
            break;
        }
    }
    for(int i =0; i < l;i++){
        if( s[i] >='0' && s[i] <= '9' ){
            int t = s[i] - '0';
            _time *= 10;
            _time += t;
        }
    }
    
}

void read_one_data(){
    cin >> n;
    read_line_cnt=n;

    time_complex();
}

int main(){
    cin >> T;
    while (T--) {
        sta.clear();
        max_time = 0;           // 最大指数归零
        err_flag = 0;           // 错误标记归零
        cnt=0;                  // 存活变量数归零
        read_line_cnt = 0;      // 剩余行数归零
        read_one_data();
    }
}