// HDU 2084
#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int a[101][101];
int dp[101][101];
int main()
{
    // freopen("input.txt", "r", stdin);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                cin >> a[i][j];
            }
        }
        dp[0][0] = a[0][0];
        for (int l = 1; l < N; ++l) {
            dp[l][0] = dp[l - 1][0] + a[l][0];
            for (int e = 1; e < l + 1; ++e) {
                dp[l][e] = max(dp[l - 1][e], dp[l - 1][e - 1]) + a[l][e];
            }
        }
        int ans = dp[N - 1][0];
        for (int i = 1; i < N; ++ i) {
            ans = max(ans, dp[N - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}