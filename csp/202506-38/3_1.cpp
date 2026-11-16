#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


//测试点1~3：只含有复杂消息，并且散列值与所有出现的代号都不匹配

using namespace std;
typedef long long ll;
int n;


//把message第l位到第r位的二进制转换成十进制
ll getnum(string message,int l,int r){
    ll num=0;
    for(int i=l;i<=r;i++){
        num=num*2+(message[i]-'0');
    }
    return num;
}

//把代号的数字表示转换回原来的代号
string getname(ll num){
    char name[20];
    for(int i=10;i>=0;i--){
        int x=num%38;
        num/=38;

        if(x==0){
            name[i]=' ';
        }else if(x<=10){
            name[i]='0'+x-1;
        }else if(x<=36){
            name[i]='A'+x-11;
        }else{
            name[i]='_';
        }
    }

    string res="";
    for(int i=0;i<11;i++){
        res+=name[i];
    }

    //不足11位时补在末尾的空格不属于原代号
    while(res.size()>0 && res[res.size()-1]==' '){
        res.pop_back();
    }
    return res;
}


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        string message;
        cin >> message;

        //复杂消息的第1~58位是完整代号的数字表示
        ll num=getnum(message,1,58);
        string name=getname(num);

        //最后一位为0：完整代号是发送方，接收方散列无法推断
        if(message[71]=='0'){
            cout << "### " << name << endl;
        }else{
            //最后一位为1：完整代号是接收方，发送方散列无法推断
            cout << name << " ###" << endl;
        }
    }

    return 0;
}
