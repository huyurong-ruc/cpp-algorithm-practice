#include <iostream>

using namespace std;

int main(){
    int x;
    cin >> x;
    int flag1 = (x%2==0)? 1:0;
    int flag2=(x>4&&x<=12)?1:0;
    if(flag1&&flag2){
        cout << 1;
    }else{
        cout << 0;
    }
    cout << " ";
    if(flag1||flag2){
        cout << 1;
    }else{
        cout << 0;
    }
    cout << " ";
    if((flag1&&!flag2)||(!flag1&&flag2)){
        cout << 1;
    }else{
        cout << 0;
    }
    cout << " ";
    if(!flag1&&!flag2){
        cout << 1;
    }else{
        cout << 0;
    }
    cout << " ";
}