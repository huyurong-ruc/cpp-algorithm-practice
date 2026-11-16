#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;
int n;
int a[100005];
int m;


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        a[i]=x+a[i-1]; // for会超时
    }
    cin >> m;
    while(m--){
        int l,r;
        cin >> l >> r;
        cout << a[r]-a[l-1]<<endl;
    }
    return 0;
}
