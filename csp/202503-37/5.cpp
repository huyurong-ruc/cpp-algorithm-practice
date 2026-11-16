#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
//n,m <=3000,A
//n,m <= 100000,AB
//n,m <= 100000,A
//n,m <= 100000
typedef long long ll;

ll a[100005];

int path[10005][10005];

int n,m;

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    while((n-1)--){
        int u,v;
        cin >> u >> v;
        path[u][v]=1,path[v][u]=1;
    }
    while(m--){
        int ops;
        cin >> ops;
        if(ops==1){
            int u;
            cin >> u;

        }else if(ops==2){
            int u,x;
            cin >> u >> x;
            a[u]=x;


        }else if(ops==3){
            int u;
            cin >> u;



        }else{
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            path[a][b]=0,path[b][a]=0,path[c][d]=1,path[d][c]=1;

            
        }
    }
    
    return 0;
}
