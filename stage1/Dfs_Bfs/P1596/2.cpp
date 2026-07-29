#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;
int n, m;
int vis[200][200];
char arr[200][200];
int dx[10] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[10] = {-1, 0, 1, 1, -1, -1, 0, 1};
int res = 0;

void dfs(int x, int y) {
//   if (x == n && y == m)
//     return;
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx>0 && nx<=n && ny>0 && ny<=m && arr[nx][ny]=='W'&&vis[nx][ny]==0){
        vis[nx][ny]=1;
        dfs(nx,ny);
    }
  }
}
struct Pos{
    int x,y;
};
void bfs(int x,int y){
    queue<Pos>q;
    q.push({x,y});
    while(!q.empty()){
        Pos head=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=head.x+dx[i];
            int ny=head.y+dy[i];
            if(nx>0 && nx<=n && ny>0 && ny<=m && arr[nx][ny]=='W'&&vis[nx][ny]==0){
                q.push({nx,ny});
                vis[nx][ny]=1;
                
            }
        }
    }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if(arr[i][j]=='W'&& vis[i][j]==0){
        vis[i][j] = 1;
        res++;
        bfs(i, j);
        // cout << i << " " << j << endl;
      }

    }
  }
  cout << res;
  return 0;
}
