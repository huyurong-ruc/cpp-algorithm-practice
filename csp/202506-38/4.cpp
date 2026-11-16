#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

// n<=15 30 scores

using namespace std;
typedef long long ll ;
ll n,m;
ll dp[20][4][7][2][2];
int fixedpos[20];
int mod=998244353;
string a="ccf",b="cspark";

int getnext(string s,int now,char ch){
    string tmp="";
    for(int i=0;i<now;i++){
        tmp+=s[i];
    }
    tmp+=ch;

    int ans=0;
    for(int len=0;len<=s.size();len++){
        if(len>tmp.size())continue;
        int flag=1;
        for(int i=0;i<len;i++){
            if(tmp[tmp.size()-len+i]!=s[i]){
                flag=0;
                break;
            }
        }
        if(flag)ans=len;
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        fixedpos[x]=1;
    }

    // dp[i][x][y][have][ok]
    // 前i位已经填完，x表示当前后缀匹配ccf前x位，y表示当前后缀匹配cspark前y位
    // have表示前面是否出现过ccf，ok表示是否已经出现过ccf在cspark左边
    dp[0][0][0][0][0]=1;

    for(int i=0;i<n;i++){
        for(int x=0;x<=3;x++){
            for(int y=0;y<=6;y++){
                for(int have=0;have<=1;have++){
                    for(int ok=0;ok<=1;ok++){
                        if(dp[i][x][y][have][ok]==0)continue;

                        for(char ch='a';ch<='z';ch++){
                            if(fixedpos[i+1]){
                                ch='#';
                            }

                            int nx=getnext(a,x,ch);
                            int ny=getnext(b,y,ch);
                            int nhave=have;
                            int nok=ok;

                            if(nx==3){
                                nhave=1;
                            }
                            if(ny==6 && have==1){
                                nok=1;
                            }

                            dp[i+1][nx][ny][nhave][nok]+=dp[i][x][y][have][ok];
                            dp[i+1][nx][ny][nhave][nok]%=mod;

                            if(fixedpos[i+1]){
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    ll res=0;
    for(int x=0;x<=3;x++){
        for(int y=0;y<=6;y++){
            for(int have=0;have<=1;have++){
                res+=dp[n][x][y][have][1];
                res%=mod;
            }
        }
    }

    cout << res;
    return 0;
}
