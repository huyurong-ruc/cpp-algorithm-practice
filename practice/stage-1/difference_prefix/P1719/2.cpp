#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;
int n;
int arr[150][150];
int sum[150][150];


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            
        }
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int i=1;i<=x;i++){
                for(int j=1;j<=y;j++){
                    sum[x][y]+=arr[i][j];
                }
            }
            
        }
    }
    int res=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            for(int x=1;x<=i;x++){
                for(int y=1;y<=j;y++){//起点(x,y)
                    int now=sum[i][j]-sum[x-1][j]-sum[i][y-1]+sum[x-1][y-1];
                    res=max(res,now);
                }
            }
            
        }
        
    }
    cout << res << endl;

    
    return 0;
}
