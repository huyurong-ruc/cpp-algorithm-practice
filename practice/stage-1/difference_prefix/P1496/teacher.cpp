#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll ;


int main(){
    int n;
    cin>>n;
    ll a[20001],b[20001],l=0;
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];

    sort(a,a+n);
    sort(b,b+n);

    for(int i=0;i<n;i++) {
        l+=b[i]-a[i];
        if(i+1<n && b[i]>a[i+1])//如果这条线段不是最后一条线段且与前一条线段有重复
            l-=b[i]-a[i+1];//减去重复部分
    }
    cout<<l;
    return 0;
}


