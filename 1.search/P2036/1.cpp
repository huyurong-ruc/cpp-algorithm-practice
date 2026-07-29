#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int n;
int s[20],b[20],rcd[20];
int ans=INT_MAX;


void dfs(int dep){
    if(dep>n){
        int sum_s=1,sum_b=0,tot=0;;
        for(int i=1;i<=n;i++){
            if(rcd[i]==1){
                sum_s*=s[i];
                sum_b+=b[i];
            }
            tot+=rcd[i];
        }
        if(tot!=0){
            int cha=abs(sum_b-sum_s);
            ans=min(ans,cha);
        }
        return;
    }
    for(int i=0;i<=1;i++){
        rcd[dep]=i;
        dfs(dep+1);
    }
}




int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i] >> b[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}