#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

// max / min -> binary_answer

using namespace std;
typedef long long ll;
// int = 10^9

ll l,n,m;
ll d[500005];

int check(int x){ // key function
    int cnt=0,pre=0;//上一个石头
    for(int i=1;i<=n+1;i++){
        if(d[i]-pre<x){//距离小于最短跳跃距离就搬走
            cnt++;
        }else{
            pre=d[i];
        }
    }
    return cnt>m;
}

ll binary_search(ll left,ll right){
    while(left<right){
        ll mid=(left+right)/2;//枚举答案，即最短跳跃距离，找第一个不可行的
        if(check(mid)){//失败
            right=mid;
        }else{
            left=mid+1;
        }
    }
    return left;
}

int main(){
    cin >> l >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> d[i];
    }
    d[n+1]=l;
    ll pos=binary_search(1,l+1);
    cout << pos-1;
    return 0;
}
