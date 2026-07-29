#include <iostream>
using namespace std;
int main(){
    int apple[15];
    for(int i=0;i<10;i++){
        cin >> apple[i];
    }
    int tao;
    cin >> tao;
    tao+=30;
    int sum=0;
    for(int i=0;i<10;i++){
        if(apple[i]<=tao){
            sum++;
        }
    }
    cout << sum;
}