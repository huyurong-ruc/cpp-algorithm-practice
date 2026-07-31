#include <cstring>
#include <iostream>
#include <iomanip>


using namespace std;
int n,r;
int rcd[50];
int used[50]={0};

void dfs(int dep){
    if(dep>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=rcd[i];
        }
        if(sum==r){
            for(int i=1;i<=n;i++){
                if(rcd[i]==1)cout << setw(3) << i;
            }
            cout << endl;
        }
        
        return;
    }
    rcd[dep]=1;
    dfs(dep+1);
    rcd[dep]=0;
    dfs(dep+1);
    
}


int main(){
    cin >> n >> r;
    dfs(1);

    return 0;
}
