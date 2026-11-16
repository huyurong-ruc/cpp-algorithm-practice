#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n,k;
int L[100005];

int check(int x){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=(L[i]/x);
    }
    return (sum>=k);
}

int binary_search(int l,int r){
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)){//找最大的l使得符合条件，mid符合，那么左边都符合，所以找第一个不符合的
            // fuhe
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return l;
}

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> L[i];
    }
    sort(L+1,L+n+1);
    int pos=binary_search(1,L[n]);
    cout << pos-1;
    
    return 0;
}
