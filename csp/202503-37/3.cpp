#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
int n;

struct node{
    string name;
    int length;
};

int main(){
    cin >> n;
    vector<node> list;
    while(n--){
        int num;
        cin >> num;
        if(num==1){
            string var;//怎么处理多个expr？？？？
            cin >> var;
            char expr[9999];
            fgets(expr,999,stdin);
            string now;
            int now_length=0;
            int flag=0;
            for(int i=0;i<9999;i++){
                if(expr[i]=='\n'){
                    if(flag){//$
                        int find=0;
                        for(int j=0;j<list.size();j++){
                            if(list[j].name==now){//出现过，更新该节点
                                find=1;
                                now_length+=list[j].length;
                                break;
                            }
                        }
                    }else{
                        now_length+=now.size();
                    }
                    now="";
                    flag=0;
                    break;
                }
                if(expr[i]==' '){
                    //现在的now成熟了，得到了完整的变量值
                    if(flag){//$
                        int find=0;
                        for(int j=0;j<list.size();j++){
                            if(list[j].name==now){//出现过，更新该节点
                                find=1;
                                now_length+=list[j].length;
                                break;
                            }
                        }
                    }else{
                        now_length+=now.size();
                    }
                    now="";
                    flag=0;
                    continue;
                }
                if(expr[i]=='$'){
                    flag=1;
                    continue;
                }
                
                now+=expr[i];
            }

            int find=0;
            for(int i=0;i<list.size();i++){
                if(list[i].name==var){//出现过，更新该节点
                    find=1;
                    list[i].length=now_length;
                }
            }
            if(!find){//push new
                list.push_back({var,now_length});
            }
        }else if(num==3){
            string var;
            cin >> var;
            int flag=0;
            for(int i=0;i<list.size();i++){
                if(list[i].name==var){
                    cout << list[i].length %(1000000007) << endl;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                cout << 0 << endl;
            }
        }
    }

    
    return 0;
}
