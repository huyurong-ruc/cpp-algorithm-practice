#include <iomanip>
#include <iostream>

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
        dfs(i, j);
        // cout << i << " " << j << endl;
      }

    }
  }
  cout << res;
  return 0;
}
