#include <iostream>
using namespace std;

struct Pos {
    int x,y;
    int step;
};

queue<Pos> q;

int n,m,sx,sy; // sx = start x

int board[405][405];
int visited[405][405]; //vis[x][y] = 1 表示被访问过
int dir[8][2] = {
    2,1,
    2,-1,
    -2,1,
    -2,-1,
    1,2,
    1,-2,
    -1,2,
    -1,-2
};

void bfs(int x,int y) {
    q.push({x,y,0});
    visited[x][y] = 1;
    board[x][y] = 0;

    while( q.empty() == false) {
        Pos head = q.front();
        q.pop();

        for(int i = 0 ;i<8 ;i++) {
            int nx = head.x + dir[i][0];
            int ny = head.y + dir[i][1];

            if( nx >n || nx < 1 || ny < 1 || ny > m) continue;
            if( visited[nx][ny] == 1) continue;

            q.push({nx,ny,head.step+1});
            visited[nx][ny] = 1;
            board[nx][ny] = head.step + 1;
        }

    }
}

int main (int argc, char *argv[]) {
    std::cin >> n >> m >> sx >> sy;
    for(int i = 1;i <= n ;++i ) // i: 1->n
        for(int j = 1;j <= m ;++j ) // j: 1->n
            board[i][j] = -1;
    // memset

    bfs(sx,sy);

    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        for(int j = 1;j <= m ;++j ) // j: 1->n
        {
            std::cout << board[i][j]<< " ";
        }
        std::cout  << "\n";
    }
    return 0;
}