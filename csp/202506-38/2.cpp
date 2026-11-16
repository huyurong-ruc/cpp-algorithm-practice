#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


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

void dfs(int x,int y,int step){
    if(step==0) return;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(yes(nx,ny)&&step>visited[nx][ny]){
            visited[nx][ny]=step;
            dfs(nx,ny,step-1);
            
        }
    }
}

int main(){
    cin >> n >> k >> x >> y;
    visited[x][y]=k+1;
    dfs(x,y,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum+=(visited[i][j]>0);
        }
    }
    cout << sum;   
    return 0;
}
