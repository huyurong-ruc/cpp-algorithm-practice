#include <iostream>
using namespace std;

int n;
int cnt=0;
int lie[20]={0};
int xie1[100]={0},xie2[100]={0};
int rcd[20];

void set(int x,int y){
    lie[y]=1;
    xie1[x+y]=1;
    xie2[x-y+n]=1;
}

void unset(int x,int y){
    lie[y]=0;
    xie1[x+y]=0;
    xie2[x-y+n]=0;
}

int is_right(int x,int y){
    if(lie[y]==0&&xie1[x+y]==0&&xie2[x-y+n]==0){
        return 1;
    }
    return 0;
}

void dfs(int x){//第x行
    if(x>n){
        cnt++;
        if(cnt<=3){
            for(int i=1;i<=n;i++){
                cout << rcd[i]<< " ";
            }
            cout << endl;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(is_right(x,i)){
            set(x,i);
            rcd[x]=i;
            dfs(x+1);
            unset(x,i);
        }
    }
}

int main(){
    cin >> n;
    dfs(1);
    cout << cnt;
    return 0;
    
}