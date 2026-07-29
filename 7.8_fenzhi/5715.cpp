#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int arr[5];
    arr[0]=a,arr[1]=b,arr[2]=c;
    sort(arr,arr+3);
    for(int i=0;i<=2;i++){
        cout << arr[i]<<" ";
    }
}