#include <iostream>
using namespace std;
int main(){
    int x,n;
    cin >> x >> n;
    int sum=0;
    for(int i=0;i<n;i++){
        int today=(x+i)%7;
        if(today==0||today==6){
            continue;
        }else{
            sum+=250;
        }
    }
    cout << sum;
}