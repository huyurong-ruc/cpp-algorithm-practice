#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int bendi=5*n;
    int luogu=11+3*n;
    if(bendi<luogu){
        cout << "Local";
    }else{
        cout << "Luogu";
    }
}