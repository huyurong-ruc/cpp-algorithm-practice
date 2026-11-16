#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n,m;
int a[1000005],b[1000005];

int check(int p){
    int h=p;
    long long sum=0;
    for(int i=1;i<=n;i++){
        sum+=max(a[i]-h,0);
    }
    return sum>=m;
}

int binary_search(int l,int r){//二分查找答案
    while(l<r){
        int mid=(l+r)/2;
        // if(check(mid)){//答案可行
        //     l=mid;
        // }else{
        //     r=mid-1;
        // }
        if(!check(mid)){//答案bu可行
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int pos=binary_search(1,a[n]+1);
    cout << pos-1;
    return 0;
}
