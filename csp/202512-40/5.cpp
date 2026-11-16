#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


// n,q,sum_m <= 10,权值值域上限1000，20分

using namespace std;
int n,w,q;

struct node{
    int flag;
    vector<int> arr;
};

node packet[20];
vector<int> value;
vector<vector<int>> group;

//判断value[now]能不能放进第x个子数据包
int check(int now,int x){
    for(int i=0;i<group[x].size();i++){
        if((value[now]^group[x][i])<w){
            return 0;
        }
    }
    return 1;
}

//判断能不能把所有元素分进cnt个稳定的子数据包
int dfs(int now,int cnt){
    if(now==value.size()){
        return 1;
    }

    for(int i=0;i<cnt;i++){
        if(check(now,i)){
            int empty=group[i].empty();
            group[i].push_back(value[now]);
            if(dfs(now+1,cnt)){
                return 1;
            }
            group[i].pop_back();

            //空的子数据包都是一样的，只需要尝试第一个
            if(empty){
                break;
            }
        }
    }
    return 0;
}

//计算一个数据包的维修代价
int calculate(vector<int> a){
    if(a.size()==0){
        return 0;
    }

    value=a;
    for(int cnt=1;cnt<=value.size();cnt++){
        group.clear();
        group.resize(cnt);
        if(dfs(0,cnt)){
            return cnt;
        }
    }
    return value.size();
}


int main(){
    cin >> n >> w;
    for(int i=1;i<=n;i++){
        packet[i].flag=1;
        int m;
        cin >> m;
        for(int j=1;j<=m;j++){
            int x;
            cin >> x;
            packet[i].arr.push_back(x);
        }
    }

    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int u,x;
            cin >> u >> x;
            packet[u].arr.push_back(x);
        }else if(op==2){
            int u,v;
            cin >> u >> v;
            for(int i=0;i<packet[v].arr.size();i++){
                packet[u].arr.push_back(packet[v].arr[i]);
            }
            packet[v].flag=0;
        }else{
            int ans=0;
            for(int i=1;i<=n;i++){
                if(packet[i].flag){
                    ans+=calculate(packet[i].arr);
                }
            }
            cout << ans << endl;
        }
    }

    
    return 0;
}
