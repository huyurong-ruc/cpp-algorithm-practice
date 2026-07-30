#include <iostream>
#include <iomanip>
#include <string>


using namespace std;
int t;
struct P{
    int type;// 0常数，1非常数
    int w;
};

struct Node{
    char name;
    string x,y;
};

int length;
Node arr[200];

void push(char name,string x,string y){
    Node a{name,x,y};
    arr[length++]=a;
}

Node top(){
    return arr[length-1];
}

void pop(){
    length--;
}

bool empty(){
    return length==0;
}

P split(string s){
    P n;
    if(s[2]==1) {
        n.type=0;
    }else{
        n.type=1;
        n.w=s[-2];
    }
    return n;
}

int calculate(string x,string y){
    if(x!=y && (x=="n" || y=="n"))return 1;
    if(x==y && x=="n") return 0;
}

int main(){
    cin >> t;
    
    for(int i=1;i<=t;i++){
        int l;
        cin >> l;
        string cmplex;
        cin >> cmplex;
        // 拆复杂度
        P ming = split(cmplex);
        if(l%2==1){
            cout << "ERR" << endl;
            continue;
        }
        P ans{0,1},now{0,1};
        for(int j=1;j<=l;j++){
            char str;
            string x,y;
            cin >> str >> x >> y;
            // 计算复杂度
            if(str=='F') push(str,x,y);

            
        }
    }

    
    return 0;
}
