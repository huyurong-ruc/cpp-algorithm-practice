#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

// 
using namespace std;
int n,p;
int a[5000005];


int main(){
    cin >> n >> p;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    while(p--){
        int x,y,z;
        cin >> x >> y >> z;
        for(int i=x-1;i<=y-1;i++){
            a[i]+=z;
        }
    }
    sort(a,a+n);
    cout << a[0];

    
    return 0;
}
