#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

int s,d;

struct node{
    string name,value;
} ;

string jing[100][5];
vector<node> dong;

void printstr(string s){
    
}


int main(){
    cin >> s >> d;
    for(int i=1;i<=s;i++){
        cin >> jing[i][1] >> jing[i][2];
    }
    string huff;
    cin >> huff;
    int n;
    cin >> n;
    for(int x=1;x<=n;x++){
        int ops;
        cin >> ops;
        if(ops==1){
            int i;
            cin >> i;
            if(i<=s){
                cout << jing[i][1]<<": "<<jing[i][2]<<endl;
            }else{
                cout << dong[i-s-1].name << ": "<<dong[i-s-1].value<<endl;
            }
        }else if(ops==2){
            int i;
            cin >> i;
            if(i==0){
                string k,v;//k是字段名，v是字段值
                cin >> k >> v;

            }else{
                string v;//用表格中i的字段名，v是字段值，输出后再插入到动态表格
                cin >> v;
                if(i<=s){
                    cout << jing[i][1]<<": "<<v<<endl;
                    dong.push_back({jing[i][1],v});
                }else{
                    cout << dong[i-s-1].name << ": "<<v<<endl;
                    dong.push_back({dong[i-s-1].name,v});
                }
                
            }
            
        }else if(ops==3){
            int i;
            cin >> i;
            if(i==0){// 3 0 k v
                string k,v;//k是字段名，v是字段值
                cin >> k >> v;
                cout << k <<": " << v << endl;
            }else{ // 3 i v
                string v;//用表格中i的字段名，v是字段值，输出后再插入到动态表格
                cin >> v;
                if(i<=s){
                    cout << jing[i][1]<<": "<<v<<endl;
                }else{
                    cout << dong[i-s-1].name << ": "<<v<<endl;
                }
                
            }
        }
    }

    
    return 0;
}
