#include <iostream>
#include <iomanip>


using namespace std;
int n;
int vis[20]={0};
int rcd[20];


//排列用used，组合直接0/1

void dfs(int dep){
    if(dep>n){
        for(int i=1;i<=n;i++){
            cout << setw(5) << rcd[i];
        }
        cout << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            rcd[dep]=i;
            dfs(dep+1);
            vis[i]=0;
        }
    }
}

int main(){
    cin >> n;
    dfs(1);

    return 0;
}
