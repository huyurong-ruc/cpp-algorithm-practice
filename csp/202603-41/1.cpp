#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n;



int main(){
    cin >> n;
    int list1[200],list2[200];
    for(int i=1;i<=n;i++){
        long double x;
        cin >> x;
        int a=x/1;
        int b=x*10-a*10;
        if(b==5){
            if(a%2==0){
                list2[i]=a;
            }else{
                list2[i]=a+1;
            }
            if(b<=4){
                list1[i]=a;
            }else {
                list1[i]=a+1;
            }
        }else{
            if(b<=4){
                list1[i]=a;
                list2[i]=a;
            }else {
                list1[i]=a+1;
                list2[i]=a+1;
            }
        }
        

    }
    for(int i=1;i<=n;i++){
        cout << list1[i] << " ";
    }
    cout << endl;
    for(int i=1;i<=n;i++){
        cout << list2[i] << " ";
    }

    
    return 0;
}
