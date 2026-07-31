#include <iostream>
#include <iomanip>


using namespace std;
int m,n;
// struct Pos{
//     int m1,m2,t1,t2;
// };
// Pos p[50];
const int MAXM=25;
const int MAXN=25;
const int MAXT=10005;

int order[MAXM * MAXN];        // 安排顺序：按顺序列出每次要安排的工件编号
int machine_id[MAXN][MAXM];         // machine_id[job][step] 工件 job 的第 step 道工序在哪台机器
int cost_time[MAXN][MAXM];          // cost_time[job][step] 工件 job 的第 step 道工序加工时长

int next_step[MAXN];                // 工件 job 下一次要安排第几道工序
int finish_time[MAXN];              // 工件 job 已安排完的最后时间（最早可开始下一道工序的时间）



void init(){
    cin >> m >> n;
    for(int i=1;i<=m*n;i++){
        cin >> order[i];
    }
    for (int job = 1; job <= n; job++)
        for (int step = 1; step <= m; step++)
            cin >> machine_id[job][step];

    for (int job = 1; job <= n; job++)
        for (int step = 1; step <= m; step++)
            cin >> cost_time[job][step];
}
int busy[500][500];

int find(int target,int start,int len){
    while(1){
        int flag=1;
        for(int t=start;t<start+len;t++){
            if(busy[target][t]){
                start++;
                flag=0;
                break;
            }
        }
        if(flag) break;
    }
    return start;
}


int func(){

    int ans=0;
    for(int i=1;i<=m*n;i++){
        int job = order[i];
        int step = ++next_step[job];
        int target = machine_id[job][step];
        int len=cost_time[job][step];
        int start = finish_time[job];
        start = find(target,start,len);
        // cout 
        for(int t=start;t<start+len;t++){
            busy[target][t]=1;
        }
        finish_time[job]=start+len;
        if(ans<finish_time[job])ans=finish_time[job];

    }
    return ans;
}


int main(){
    init();
    int ans=func();
    cout << ans;
    return 0;
}
