#include <iostream>
#include <vector>
using namespace std;
int main(){
    string isbn;
    cin >> isbn;
    int sum=0;
    int flag=0;
    for(int i=1;i<=11;i++){
        if(isbn[i-1]=='-'){
            flag++;
            continue;
        }
        sum+=(isbn[i-1]-'0')*(i-flag);
    }
    int yushu=sum%11;
    if(yushu==10){
        if(isbn[12]=='X'){
            cout <<"Right";
        }else{
            isbn[12]='X';
            cout << isbn;
        }
        return 0;
    }
    if(isbn[12]-'0'==sum %11){
        cout <<"Right";
    }else{
        isbn[12]=sum%11+'0';
        cout << isbn;
    }
    
}