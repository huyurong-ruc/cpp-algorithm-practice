#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n,m;
int a[1000005];
int target;

int binary_search(int l,int r){
    while(l<r){
        int mid=(l+r)/2;
        if(a[mid]<target){
            l=mid+1;
        }else{ // >=target
            r=mid;
        }
    }
    return l;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    while(m--){
        cin >> target;
        int pos=binary_search(1,n+1);
        if(pos==n+1 || a[pos]!=target){
            cout << "-1" << " ";
        }else{
            cout << pos << " ";
        }
    }
    
    return 0;
}
