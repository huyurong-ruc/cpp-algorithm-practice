#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int sub[maxn];

int n;
int m;

int main() {
    std::cin >> n >> m;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        std::cin >> a[i];
        sub[i] = a[i] - a[i-1];
    }

    for(int i = 1;i <= m ;++i ) // i: 1->m
    {
        int l,r,add;
        std::cin >> l >> r >> add;
        sub[l] += add;
        sub[r+1] -= add;
    }
    int sum = 0;
    int ans = 99999999;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        sum += sub[i];
        if( ans > sum) ans = sum;
    }
    std::cout << ans << "\n";


    return 0;
}