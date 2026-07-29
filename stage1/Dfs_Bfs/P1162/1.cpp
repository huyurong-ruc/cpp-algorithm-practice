#include <iostream>
#include <iomanip>
#include <queue>
#include <utility>


using namespace std;
int n;
int arr[50][50];
int vis[50][50];
int dx[5]={0,0,-1,1};
int dy[5]={1,-1,0,0};

void bfs(){
    queue<pair<int, int>>q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<=n+1&&ny>=0&&ny<=n+1&&vis[nx][ny]==0 && arr[nx][ny]==0){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}


int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    bfs();
    // for(int i=0;i<=n+1;i++){
    //     for(int j=0;j<=n+1;j++){
    //         cout << vis[i][j]<<" ";
    //     }
    //     cout << endl;
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]==1){
                cout << "0" << " ";
            }else if(arr[i][j]==1){
                cout << "1" << " ";
            }else{
                cout << "2" << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
