#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
typedef long long ll ;
ll n,m;
ll a[100005];
ll record[100005];

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){//i个苹果的最大快乐值
        int res=-1;
        for(int j=1;j<=i;j++){
            if(record[i-j]+a[j]>res) res=record[i-j]+a[j];
        }
        record[i]=res;
    }
    cout <<record[n];
    return 0;
}
