#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

// 40%不存在特殊类型进程
// 40%不存在C类进程
// n<=10, m<=40. st<=20, w<=20, k<=40, t<=20, a<=m
using namespace std;
int n,m;//m种资源，申请1-m号资源
int resources[100];

struct task{
    int a;//申请的资源编号
    int t;//持续段数
};

struct jincheng{
    int k;//k个运行列表
    vector<task> list;
    int benefit;//总收益
    int duanshu;//持续段数
};

int main(){
    cin >> n >> m;
    jincheng J[20];
    for(int i=1;i<=n;i++){
        char type;
        cin >> type;
        if(type=='X'){ //进程i为普通进程
            int st,k; //i进程从第st段首开始活动，对a1发起申请
            cin >> st >> k;
            J[i].k=k;
            for(int j=1;j<=k;j++){ //k个运行列表
                int a,t;//i号进程第j次运行任务前申请的资源编号、持续段数
                cin >> a >> t;
                J[i].list.push_back({a,t});
            }
        }
    }


    for(int i=1;i<=n;i++){
        cout << J[i].benefit << " " << J[i].duanshu << endl;
    }

    
    return 0;
}
