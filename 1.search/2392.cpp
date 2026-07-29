#include <climits>
#include <iostream>
using namespace std;
int s[5];
int a[50];
int ans;
int n;
int rcd[50];//记录放在0/1桶
int tot=0;

void dfs(int dep){
    if(dep>n){
        int left=0,right=0;
        for(int i=1;i<=n;i++){
            if(rcd[i]==0){
                left+=a[i];
            }else{
                right+=a[i];
            }
        }
        int t=max(left,right);
        ans=min(ans,t);
        return;
    }
    for(int i=0;i<=1;i++){//尝试0/1桶
        rcd[dep]=i;//dep指第几个人
        dfs(dep+1);
    }
}

int main(){
    for(int i=1;i<=4;i++){
        cin >> s[i];
    }
    for(int i=1;i<=4;i++){ //遍历每个习题集
        n=s[i];
        for(int j=1;j<=n;j++){
            cin >> a[j];
        }
        ans=INT_MAX;
        dfs(1);
        tot+=ans;
    }
    cout << tot;
    return 0;
}