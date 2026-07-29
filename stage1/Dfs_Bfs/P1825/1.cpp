#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;
char arr[500][500];
int vis[500][500];
int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};
struct node{
    int x,y,s;
};
int sx,sy,tx,ty;
vector<node> v[30];

int bfs(){
    queue<node>q;
    q.push({sx,sy,0});
    while(!q.empty()){
        node h=q.front();
        q.pop();
        if(h.x==tx && h.y==ty)return h.s;
        for(int i=0;i<4;i++){
            int nx=h.x+dx[i],ny=h.y+dy[i];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&vis[nx][ny]==0){
                vis[nx][ny]=1;
                if(arr[nx][ny]>='A'&&arr[nx][ny]<='Z'){
                    int t=arr[nx][ny]-'A';
                    for(int j=0;j<v[t].size();j++){
                        if(v[t][j].x!=nx || v[t][j].y!=ny){
                            nx=v[t][j].x;
                            ny=v[t][j].y;
                            break;
                        }
                    }
                    q.push({nx,ny,h.s+1});
                }else q.push({nx,ny,h.s+1});
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='#')vis[i][j]=1;
            if(arr[i][j]=='@')sx=i,sy=j;
            if(arr[i][j]=='=')tx=i,ty=j;
            if(arr[i][j]>='A'&&arr[i][j]<='Z')v[arr[i][j]-'A'].push_back({i,j,0});
        }
    }
    vis[sx][sy]=1;
    int res=bfs();
    cout << res;
    return 0;
}
