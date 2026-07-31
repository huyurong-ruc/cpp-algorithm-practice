#include <iostream>
#include <iomanip>


using namespace std;

int n,m,t;
int sx,sy,fx,fy;
int arr[10][10]={0};
int dx[10]={0,0,1,-1};
int dy[10]={1,-1,0,0};
int res=0;
int vis[10][10]={0};

void dfs(int x,int y){
    if(x==fx && y==fy){
        res++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0 && nx<=n && ny>0 && ny<=m && arr[nx][ny]==0 ){//可走
            // && vis[nx][ny]==0
            // vis[nx][ny] = 1;
            arr[nx][ny]=1;
            dfs(nx,ny);
            arr[nx][ny]=0;
            // vis[nx][ny] = 0;

        }
    }

}


int main(){
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for(int i=1;i<=t;i++){
        int x,y;
        cin >> x >> y;
        arr[x][y]=1;
    }
    arr[sx][sy]=1;
    // vis[sx][sy]=1;
    dfs(sx,sy);
    cout << res;

    
    return 0;
}
