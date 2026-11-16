#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;
int n,k,x,y;
int visited[200][200];
int sum=0;

int dx[10]={-2,-2,-1,-1,1,1,2,2};
int dy[10]={1,-1,2,-2,2,-2,1,-1};

int yes(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=n)return 1;
    return 0;
}
 
int main(){
    cin >> n >> k >> x >> y;
    visited[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int, int> now=q.front();
        q.pop();

        if(visited[now.first][now.second]>k) continue;

        for(int i=0;i<8;i++){
            int nx=now.first+dx[i];
            int ny=now.second+dy[i];
            if(yes(nx, ny)&&!visited[nx][ny]){
                visited[nx][ny]=visited[now.first][now.second]+1;
                q.push({nx,ny});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum+=(visited[i][j]>0);
        }
    }
    cout << sum;   
    return 0;
}

