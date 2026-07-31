#include <iostream>
#include <climits>
using namespace std;
int s[5];
int tot = 0;
int ans ;
int a[100];
int rcd[100];
int tot_problem_time = 0;
int n = 0;

void dfs(int dep) {
    if( dep > n) {
        // for(int i =1;i<=n;i++) cout << rcd[i] << " ";
        // cout << " -- > ";
        int left = 0;
        for(int i =1;i<=n;i++) {
            if( rcd[i] == 0) left += a[i];
        }
        int right = tot_problem_time - left;
        int t = max(right,left);
        ans = min(ans,t);
        // cout  << " left : " << left << " ";
        // cout  << " right: " << right<< " ";
        // cout <<endl;
        return;
    }
    for(int i =0;i<=1;i++) 
    {
        rcd[dep] = i;
        dfs(dep+1);
    }
}
int main(){
    cin >> s[1];
    cin >> s[2];
    cin >> s[3];
    cin >> s[4];

    int sz = 4;
    for(int k  = 1;k<=4;k++){
        // 读取题目
        tot_problem_time = 0;
        for(int i =1;i<=s[k];i++) {
            cin >> a[i];
            tot_problem_time += a[i];
        }
        ans = INT_MAX;
        n = s[k];
        dfs(1);
        // cout << " ans " << ans << endl;
        // cout << " ================ \n";
        tot += ans;
    }
    cout << tot;

    return 0;
}