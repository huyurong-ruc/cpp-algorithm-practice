#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
stack<string> myStack;
vector<string> vec;
int t,now_cmp=0,final_ans=-1,yuce;

void split(string cmplex){
    if(cmplex[2] != '1'){
        int now=0;
        for(int i=4;i<cmplex.size()-1;i++){
            now+=(cmplex[i]-'0')*pow(10,(cmplex.size()-2-i));
        }
        yuce=now;
    }
}

int deal_F(string s,string name,string x,string y){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==name){
            cout << "ERR" << endl;
            return -1;
        }
    }
    myStack.push(name);
    vec.push_back(name);
    if(x>=y){
        return 0;
    }
    else if(y=="n") {
        return 1;
    }
    return 0;
}

int deal_E(){
    if(myStack.empty()){
        cout << "ERR" << endl;
        return -1;
    }else{
        myStack.pop();
        vec.pop_back();
        final_ans=max(final_ans,now_cmp);
        return 1;
    }
}

int deal_one(){
    string s;
    cin >> s ;
    if(s=="F"){
        string name,x,y;
        cin >> name >> x >> y;
        int res=deal_F(s,name,x,y);
        if(res==-1) return -1;
        if(myStack.size()==1){//之前栈是空的
            final_ans=max(final_ans,now_cmp);
        }
        now_cmp += res;
        
        
    }else{
        int x=deal_E();
        if(x==-1)return -1;
    }
    return 1;
}

int main(){
    cin >> t;
    while(t--){
        myStack={};
        vec={};
        final_ans=-1,now_cmp=0;
        int l;
        string cmplex;
        cin >> l >> cmplex;
        split(cmplex);// 拆解当前程序的小明预测复杂度
        int x;
        int flag=0;
        while(l--){
            x=deal_one();
            if(x==-1){
                while(l--){
                    char str[9999];
                    fgets(str,9999,stdin);
                }
                flag=1;
                break;
            }
        }
        if(flag)continue;
        if(!myStack.empty()){
            cout << "ERR" << endl;
            continue;
        }
        if(x==-1) continue;
        if(final_ans==yuce) {
            cout << "Yes" << endl;
        }else{
            cout <<"No" << endl;  
        } 
        
    }
}