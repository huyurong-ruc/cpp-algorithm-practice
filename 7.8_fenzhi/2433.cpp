#include <iomanip>
#include <cmath>
#include<iostream>
#include <stdio.h>
using namespace std;
// 填上你觉得需要的其他头文件
using namespace std;
int main() {
    int T;
    cin >> T;
    if (T == 1) {
        // 粘贴问题 1 的主函数代码，除了 return 0
        cout << "I love Luogu!";
    } else if (T == 2) {
        // 粘贴问题 2 的主函数代码，除了 return 0
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        // 请自行完成问题 3 的代码
        cout << 3 << endl;
        cout << 12 << endl;
        cout << 2 << endl;
    } else if (T == 4) {
        // 请自行完成问题 4 的代码
        cout  << setprecision(6) << 500.0 / 3;
    } else if (T == 5) {
        // 请自行完成问题 5 的代码
        cout << 480/32 << endl;
    } else if (T == 6) {
        // 请自行完成问题 6 的代码
        cout << sqrt(36+81)<< endl;
    } else if (T == 7) {
        // 请自行完成问题 7 的代码
        cout << 110 << endl;
        cout << 90 << endl;
        cout << 0;
    } else if (T == 8) {
        // 请自行完成问题 8 的代码
        cout << 2*3.141593*5<< endl;
        cout << 3.141593*25 << endl;
        cout << 4.0/3*3.141593*125;
    } else if (T == 9) {
        // 请自行完成问题 9 的代码
        cout << 22;
    } else if (T == 10) {
        // 请自行完成问题 10 的代码
        cout << 9;
    } else if (T == 11) {
        // 请自行完成问题 11 的代码
        cout << 100.0/3;
    } else if (T == 12) {
        // 请自行完成问题 12 的代码
        printf("%d\n",'M'-'A'+1);
        printf("%c",'A'+17);
    } else if (T == 13) {
        // 请自行完成问题 13 的代码
        int sum=4.0/3*3.141593*(64+1000);
        printf("%d",int(pow(sum,1.0/3)));
    } else if (T == 14) {
        // 请自行完成问题 14 的代码
        cout << 50;
    }
    return 0;
}