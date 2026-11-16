#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

int b,c,l,r;

int f(int x){
    return x*x+b*x+c;
}

int main(){
    long long s=0;
    cin >> b >> c >> l >> r;
    if(l%2==0){
        for(int x=l;x<=r;x+=2){
            s+=f(x);
        }
    }else{
        for(int x=l+1;x<=r;x+=2){
            s+=f(x);
        }
    }
    cout << s*2;
    
    return 0;
}
