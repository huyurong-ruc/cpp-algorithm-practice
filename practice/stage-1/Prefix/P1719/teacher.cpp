#include <bits/stdc++.h>
using namespace std;

const int maxn = 130;


int n;
int matrix[maxn][maxn];
int sum[maxn][maxn];

int get_max_endxy(int ex,int ey) {

    // 枚举起点
    int ans = 0;
    for(int sx = 1;sx <= ex;sx ++) {
        for(int sy = 1;sy <= ey;sy ++) {
            int t = sum[ex][ey] - sum[sx-1][ey] - sum[ex][sy-1] + sum[sx-1][sy-1];
            ans = max(ans,t);
        }
    }
    return ans;

}

int main (int argc, char *argv[]) {

    std::cin >> n;

    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        for(int j = 1;j <= n ;++j ) // j: 1->n
        {
            std::cin >> matrix[i][j];
        }
    }

    for(int i = 1;i<=n;i++) {
        int tot = 0;
        for(int j = 1;j<= n;j ++) {
            // 枚举终点
            tot += matrix[i][j];
            sum[i][j] = sum[i-1][j] + tot;
            // std::cout << sum[i][j]<< " ";
        }
        // std::cout << "\n";
    }

    int ans = 0;
    for(int i = 1;i<=n;i++) {
        int tot = 0;
        for(int j = 1;j<= n;j ++) {
            // 枚举终点
            int t = get_max_endxy(i,j);
            ans = max(ans,t);
        }
    }
    std::cout << ans << "\n";


    return 0;
}