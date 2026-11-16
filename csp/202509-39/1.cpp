#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n,a;


int main(){
    cin >> n >> a;
    int m=0;
    for(int i=1;i<=n;i++){
        double x,y;
        cin >> x >> y;
        if(x*x+y*y<=a*a)m+=1;
    }
    printf("%lf",4.0*m/n);

    
    return 0;
}
