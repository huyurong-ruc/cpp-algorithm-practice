#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll ;
int k;


int main(){
    cin >> k;
    while(k--){
        ll u,o,n;
        cin >> u >> o >> n;
        ll x=(n-u)*100/o;//1.4999
        ll x1=x/10;//149.99/10=14
        ll x2=x%10;//149*10=9.99/1=9
        cout << x1+1 << " " << x2+1 <<endl;
        
        
    }

    
    return 0;
}
