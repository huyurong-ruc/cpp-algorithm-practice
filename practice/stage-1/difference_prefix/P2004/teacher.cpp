#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

ll n, m, c;
ll sum[1005][1005];

int main() {
    cin >> n >> m >> c;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            ll value;
            cin >> value;

            sum[i][j] = value
                      + sum[i - 1][j]
                      + sum[i][j - 1]
                      - sum[i - 1][j - 1];
        }
    }

    ll answerX = 0;
    ll answerY = 0;
    ll maxValue = LLONG_MIN;

    for (ll i = 1; i <= n - c + 1; i++) {
        for (ll j = 1; j <= m - c + 1; j++) {
            ll x2 = i + c - 1;
            ll y2 = j + c - 1;

            ll current =
                sum[x2][y2]
                - sum[i - 1][y2]
                - sum[x2][j - 1]
                + sum[i - 1][j - 1];

            if (current > maxValue) {
                maxValue = current;
                answerX = i;
                answerY = j;
            }
        }
    }

    cout << answerX << " " << answerY;

    return 0;
}