#include <iostream>
using namespace std;
int n;
int rcd[20];



void dfs(int dep){
    if(dep>n){
        for(int i=1;i<=n;i++){
            if(rcd[i]==0){
                cout << "N";
            }else{
                cout << "Y";
            }
        }
        cout << endl;
        return;
    }
    for(int i=0;i<=1;i++){
        rcd[dep]=i;
        dfs(dep+1);
    }
}



int main(){
    
    cin >> n;
    dfs(1);

}