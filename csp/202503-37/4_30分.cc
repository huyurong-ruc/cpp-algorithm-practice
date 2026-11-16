#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
//n <= 1000,a_i <=100000

using namespace std;
int n;
int a[1000005];
typedef long long ll ;
int gcdlist[10005][10005];


ll gcd(int l,int r){
    if(l==r){
        gcdlist[l][r]=a[l];
        return a[l];
    }
    int ans=-1;
    //找a数组中l-r下标的最大公约数
    // int maximism=-1;
    // for(int i=l;i<=r;i++){
    //     maximism=max(maximism,a[i]);
    // }
    for(int i=min(gcdlist[l][r-1],a[r]);i>=1;i--){
        int flag=0;
        for(int j=l;j<=r;j++){
            if(a[j]%i!=0){
                flag=1;
                break;
            }
        }
        if(!flag){
            ans=i;
            break;
        }
    }
    gcdlist[l][r]=ans;
    return ans;
}

ll f(int l,int r){
    return l * r * gcd(l,r);
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
