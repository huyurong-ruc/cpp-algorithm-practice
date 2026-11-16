#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

// 40%不存在特殊类型进程
// n<=10, m<=40. st<=20, k<=40, t<=20, a<=m
using namespace std;

int n,m;//m种资源，申请1-m号资源
int resources[100];//0表示空闲，否则表示被哪个进程占用

struct task{
    int a;//申请的资源编号
    int t;//持续段数
};

struct jincheng{
    int st;//从第st段开始活动
    int k;//k个运行列表
    vector<task> list;

    int benefit;//总收益
    int duanshu;//持续段数

    int now;//当前执行到第几个任务
    int remain;//当前任务还剩多少段
    int state;//0没开始 1等待资源 2运行 3结束
};

int main(){
    cin >> n >> m;

    jincheng J[20];

    for(int i=1;i<=n;i++){
        char type;
        cin >> type;

        if(type=='X'){ //进程i为普通进程
            int st,k;
            cin >> st >> k;

            J[i].st=st;
            J[i].k=k;

            J[i].benefit=0;
            J[i].duanshu=0;
            J[i].now=0;
            J[i].remain=0;
            J[i].state=0;

            for(int j=1;j<=k;j++){ //k个运行列表
                int a,t;//申请资源编号、持续段数
                cin >> a >> t;

                J[i].list.push_back({a,t});
            }
        }
    }

    memset(resources,0,sizeof(resources));


    //一段一段模拟
    for(int s=1;;s++){
        // 段首

        //到开始时间的进程开始申请资源
        for(int i=1;i<=n;i++){
            if(J[i].state==0 && J[i].st==s){
                J[i].state=1;
            }
        }


        //request[a]表示有哪些进程在申请资源a
        vector<int> request[100];

        for(int i=1;i<=n;i++){
            if(J[i].state==1){

                int a=J[i].list[J[i].now].a;

                request[a].push_back(i);
            }
        }


        //处理资源申请
        for(int a=1;a<=m;a++){

            //资源被占用，所有人继续等
            if(resources[a]!=0)
                continue;

            //没人申请
            if(request[a].empty())
                continue;

            //编号最小的进程申请成功
            int winner=*min_element(request[a].begin(),request[a].end());

            resources[a]=winner;

            J[winner].state=2;
            J[winner].remain=J[winner].list[J[winner].now].t;
        }



        // 段中：运行

        for(int i=1;i<=n;i++){

            if(J[i].state==2){

                //这一段的收益=当前占有的资源数量
                for(int a=1;a<=m;a++){
                    if(resources[a]==i){
                        J[i].benefit++;
                    }
                }

                J[i].remain--;
            }
        }


        // 段末
        for(int i=1;i<=n;i++){

            //当前任务运行结束
            if(J[i].state==2 && J[i].remain==0){

                J[i].now++;

                //所有任务都完成
                if(J[i].now==J[i].k){

                    J[i].state=3;

                    J[i].duanshu=s-J[i].st+1;

                    //进程结束，释放它拥有的所有资源
                    for(int a=1;a<=m;a++){
                        if(resources[a]==i){
                            resources[a]=0;
                        }
                    }
                }

                //还有下一个任务
                else{
                    J[i].state=1;
                }
            }
        }


        //所有进程都结束就退出
        bool finish=true;

        for(int i=1;i<=n;i++){
            if(J[i].state!=3){
                finish=false;
                break;
            }
        }

        if(finish)
            break;
    }


    for(int i=1;i<=n;i++){
        cout << J[i].benefit << " " << J[i].duanshu << endl;
    }

    return 0;
}