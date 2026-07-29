#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int arr[5];
    arr[0]=a,arr[1]=b,arr[2]=c;
    sort(arr,arr+3);
    for(int i=arr[2];i>=2;i--){
        int flag=1;
        for(int j=0;j<=2;j++){
            if(arr[j]%i!=0)flag=0;
        }
        if(flag){
            for(int j=0;j<=2;j++){
                arr[j]=arr[j]/i;
            }
        }
    }
    cout << arr[0] << "/" << arr[2];
}