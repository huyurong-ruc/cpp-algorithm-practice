#include <iostream>
#include <algorithm>


using namespace std;
typedef long long ll;
ll n,l=99999,r=-1;

int main(){
    cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b;
        l=min(l,a);
        r=max(r,b);

    }
    cout << r-l+1;

    
    return 0;
}
