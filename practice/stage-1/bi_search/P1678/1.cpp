#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int m,n;
long long line[100005],grade[100005];
long long x;

int binary_search(int l,int r){//找第一个大于x的分数
    while(l<r){
        int mid=(l+r)/2;
        if(line[mid]>=x){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}

int main(){
    cin >> m >> n;
    for(int i=1;i<=m;i++){
        cin >> line[i];
    }
    sort(line+1,line+m+1);
    line[0]=-999999999;
    long long res=0;
    for(int i=1;i<=n;i++){
        cin >> x;
        int pos=binary_search(1,m+1);
        if(pos==1){
            res+=line[pos]-x;
        }else if(pos==m+1){
            res += (x-line[pos-1]);
        } else{
            res+=min(line[pos]-x,x-line[pos-1]);
        }
    }
    cout << res;

    
    return 0;
}
