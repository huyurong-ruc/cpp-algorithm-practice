#include <iostream>
#include <queue>
#include <cstring>


using namespace std;
int n,m,x,y;
int arr[500][500];//棋盘
int vis[500][500];
int dx[50]={1,1,2,2,-1,-1,-2,-2};
int dy[50]={2,-2,1,-1,2,-2,1,-1};
struct Pos{
    int x,y,step=0;
};



void bfs(int x,int y){
    queue<Pos> q;
    q.push({x,y,0});
    while(!q.empty()){
        Pos head=q.front();
        
        q.pop();
        for(int i=0;i<8;i++){
            int nx=head.x+dx[i];
            int ny=head.y+dy[i];
            if(nx>0 && nx<=n && ny>0 && ny<=m && vis[nx][ny]==0){
                vis[nx][ny]=1;
                arr[nx][ny]=head.step+1;
                q.push({nx,ny,head.step+1});
                // cout << nx << " " << ny << " " << head.step+1 << endl;
            }
        }
    }

}




int main(){
    cin >> n >> m >> x >> y;
    memset(arr,-1,sizeof(arr));
    memset(vis,0,sizeof(vis));
    arr[x][y]=0;
    vis[x][y]=1;
    bfs(x,y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout << endl;
    }
    
    return 0;
}
