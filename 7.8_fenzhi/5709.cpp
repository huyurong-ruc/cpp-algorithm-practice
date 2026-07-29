#include <iostream>

using namespace std;

int main(){
    int m,t,s;
    cin >> m >> t >> s;
    if(s>=m*t){
        cout << 0;
    }else if(s%t==0){
        cout << m-s/t;
    }else{
        cout << m-s/t-1;
    }
}