#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
//n <= 1000,a_i <=100000

using namespace std;
int n;
int a[1000005];
typedef long long ll ;
int gcdlist[10005][10005];


ll getgcd(int l,int r){
    if(l==r){
        gcdlist[l][r]=a[l];
        return a[l];
    }
    gcdlist[l][r]=gcd(gcdlist[l][r-1],a[r]);
    return gcdlist[l][r];
}

ll f(int l,int r){
    return l * r * getgcd(l,r);
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    ll res=0;

    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            res+=f(l,r);
        }
    }

    cout << res % 998244353;
    
    return 0;
}
