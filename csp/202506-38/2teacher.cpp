#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    // distance[i][j] 表示起点到 (i,j) 的最少步数，-1 表示未访问
    int distance[105][105];
    memset(distance,-1,sizeof(distance));

    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    // BFS 逐层扩展，先到达的步数一定最小
    queue<pair<int, int> > que;
    distance[x][y] = 0;
    que.push({x, y});
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        if (distance[now.first][now.second] == k) continue;

        for (int i = 0; i < 8; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n || distance[nx][ny] != -1) continue;
            distance[nx][ny] = distance[now.first][now.second] + 1;
            que.push({nx, ny});
        }
    }

    // 统计所有步数不超过 k 的方格
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (distance[i][j] != -1 && distance[i][j] <= k) answer++;
        }
    }
    cout << answer << '\n';
    return 0;
}