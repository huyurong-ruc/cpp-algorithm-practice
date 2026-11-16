#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll ;
ll n,m ,c;
ll arr[1005][1005];

int main(){
    cin >> n >> m >> c;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    ll x,y,value=-1;
    ll va[1005][1005];
    memset(va,0,sizeof(va));
    for(ll i=1;i<=n-c+1;i++){
        for(ll j=1;j<=m-c+1;j++){
            for(ll a=i;a<=i+c-1;a++){
                for(ll b=j;b<=j+c-1;b++){
                    va[i][j]+=arr[a][b];
                }
            }
            if(va[i][j]>value){
                x=i,y=j;
                value=va[i][j];
            }
        }
    }
    cout << x << " " << y;
    
    return 0;
}
