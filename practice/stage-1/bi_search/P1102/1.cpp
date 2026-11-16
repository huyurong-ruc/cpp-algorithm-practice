#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n,c;
int a[200005];
int target;

int binary_search(int l,int r){
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]<target){
            l=mid+1;
        }else{
            r=mid;
        }

    }
    return l;
}



int main(){
    cin >> n >> c;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long long res=0;
    for(int i=1;i<=n;i++){
        target=a[i]-c;
        int x=binary_search(1, n+1);
        target++;
        int y=binary_search(1, n+1);
        res+=(y-x);
        // target=c-a[i];
        // x=binary_search(1, n+1);
        // target++;
        // y=binary_search(1, n+1);
        // res+=(y-x);

    }
    cout << res;
    
    
    return 0;
}
