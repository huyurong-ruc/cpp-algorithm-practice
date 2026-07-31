#include <iostream>

using namespace std;

int n;
int arr[1005];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        arr[x]=1;
    }
    int sum=0;
    for(int i=1;i<=1000;i++){
        sum+=arr[i];
    }
    cout << sum<< endl;
    for(int i=1;i<=1000;i++){
        if(arr[i])cout << i << " ";
    }
    return 0;
}
