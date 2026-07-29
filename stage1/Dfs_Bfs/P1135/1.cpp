#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;
int n, a, b;
int k[300];
int vis[300];
int arr[300];
struct Pos {
  int x, step;
};

void bfs(int x) {
  queue<Pos> q;
  q.push({x, 0});
  vis[x]=1;


  while (!q.empty()) {
    int nx;
    Pos head = q.front();
    q.pop();
    // cout < head.x << " " << head.step << endl;
    for (int i = 0; i < 2; i++) {
      if (i == 0) {
        nx = head.x + k[head.x];
      } else {
        nx = head.x - k[head.x];
      }
      if (nx > 0 && nx <= n && vis[nx] == 0) {
        vis[nx] = 1;
        arr[nx] = head.step + 1;
        q.push({nx, head.step + 1});
        if (nx == b)
          return;
      }
    }
  }
}

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  
  memset(arr, -1, sizeof(arr));
  arr[a]=0;
  bfs(a);
  cout << arr[b];

  return 0;
}
