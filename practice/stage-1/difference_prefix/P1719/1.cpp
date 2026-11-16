#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>


using namespace std;
int n;
int arr[150][150];
int used[150][150];
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    int res=-1;
    for(int size1=1;size1<=n;size1++){//1*1
        for(int size2=1;size2<=n;size2++){
            for(int i=1;i<=n-size1+1;i++){
                for(int j=1;j<=n-size2+1;j++){
                    int sum=0;
                    // memset(used,0,sizeof(used));
                    for(int x=i;x<i+size1;x++){
                        for(int y=j;y<j+size2;y++){
                            sum+=arr[x][y];
                            // used[x][y]=1;
                        }
                    }
                    res=max(res,sum);
                    
                    
                }
            }
            
        }
    }
    cout << res<< endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << used[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
