#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;
int n,p;
int a[5000005];
int sub[5000005];

int main(){
    cin >> n >> p;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sub[i]=a[i]-a[i-1];
    }
    while(p--){
        int x,y,z;
        cin >> x >> y >> z;
        sub[x]+=z;
        sub[y+1]-=z;
    }
    int res=INT_MAX;
    int now=0;
    for(int i=1;i<=n;i++){
        now+=sub[i];
        res=min(res,now);
    }
    cout << res;
    
    return 0;
}
