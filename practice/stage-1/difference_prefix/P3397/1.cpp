#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;
int n,m;
int arr[1005][1005];

int main(){
    cin >> n >> m;
    while(m--){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                arr[i][j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
