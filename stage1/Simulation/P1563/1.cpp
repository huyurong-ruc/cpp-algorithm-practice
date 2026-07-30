#include <iostream>
#include <iomanip>


using namespace std;
int n,m;
struct People{
    string name;
    int out;
};
People p[100005];

// main（任何函数默认）里面只有1024KB，所以放全局
int main(){
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        cin >> p[i].out >> p[i].name;
    }
    int index=0;
    int fx[5][5];
    fx[0][0]=-1,fx[0][1]=1,fx[1][0]=1,fx[1][1]=-1;
    for(int i=1;i<=m;i++){
        int a,s;
        cin >> a >> s;
        s=s*fx[a][p[index].out];
        index = (index+(s%n)+n)%n;
        //+1.向左数s个人,a=0,out=1;a=1,out=0
        // index = (index+(s * fx[a][p[index].out] %n)+n)%n;

    }
    cout << p[index].name;
    
    return 0;
}
