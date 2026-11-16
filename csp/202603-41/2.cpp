#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll ;
ll n,k=1,m,res;

ll bianzhi(ll now){
    ll tmp=now*k;
    if(tmp%100==0){
        return tmp/100;
    }else{
        return tmp/100+1;
    }
}


ll have_a_try(ll robot){
    ll now=n;
    int flag=0;
    for(ll day=0;day<=m;day++){
        ll bad=bianzhi(now);
        now=now-bad-robot;
        if(now<0 && day!=m){
            flag=1;
            break;
        }
    }
    if(flag){
        return 0;
    }else{
        return 1;
    }
}


int main(){
    cin >> n >> k >> m;
    if(n<=10000){
        for(ll robot=n*(1.0/m-k*1.0/100)*1.0/(1-m*k*1.0/100);robot>=0;robot--){
            ll now=n;
            int flag=0;
            for(ll day=0;day<=m;day++){
                ll bad=bianzhi(now);
                now=now-bad-robot;
                if(now<0 && day!=m){
                    flag=1;
                    break;
                }
            }
            if(flag){
                continue;
            }else{
                cout <<robot;
                return 0;
            }
        }
    }else{ //最后20%大样本，二分法
        ll right= n*(1.0/m-k*1.0/100)*1.0/(1-m*k*1.0/100);
        ll left=0;
        while(left < right){
            ll mid=(right+left+1)/2;
            if(have_a_try(mid)){
                left=mid;
            }else{
                right=mid-1;
            }
        }
        cout << left;
        return 0;
    }
    
    
    return 0;
}
