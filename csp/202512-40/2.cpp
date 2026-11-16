#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll ;
int n,m;
int k[1005];



int func(int x,int k){
    return ((x*x+k*k)&7)^k;
}


int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> k[i];
    }
    

    int f[600];
    for(int i=0;i<512;i++){
        int now=i;
        for(int j=1;j<=m;j++){
            int a=(now>>6)&7,b=(now>>3)&7,c=now&7;
            int na=b,nb=c^(func(b,k[j])),nc=a^(func(c,k[j]));
            now=(na << 6) | (nb << 3) | nc;
        }
        f[i]=now;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        for(int j=0;j<512;j++){
            if(f[j]==x){
                cout << j << " ";
                break;
            }
        }
    }

    
    return 0;
}
