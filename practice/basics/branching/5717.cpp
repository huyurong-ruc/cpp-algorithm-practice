#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b<=c || a+c<=b || b+c<=a){
        cout <<"Not triangle"<< endl;
        return 0;
    }
    int arr[5];
    arr[0]=a,arr[1]=b,arr[2]=c;
    sort(arr,arr+3);
    a=arr[0],b=arr[1],c=arr[2];
    if(c*c==a*a+b*b){
        cout<<"Right triangle"<< endl;
    }else if(c*c>a*a+b*b){
        cout<<"Obtuse triangle"<< endl;
    }else{
        cout <<"Acute triangle"<< endl;
    }
    if(a==b||a==c||b==c){
        cout<<"Isosceles triangle"<<endl;
    }
    if(a==b&&a==c){
        cout <<"Equilateral triangle"<< endl;
    }
}