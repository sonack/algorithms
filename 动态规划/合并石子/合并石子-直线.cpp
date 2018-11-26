#include <iostream>
#include <algorithm>
using namespace std;


const int MAXN = 100;
int a[MAXN + 10], dp[MAXN][MAXN];
int preSum[MAXN + 10];
int main()
{
    freopen("input.txt", "r", stdin);
    int N;
    cin >> N;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        preSum[i+1] = preSum[i] + a[i];
        dp[i][i] = 0;
    }
    for (int w = 1; w < N; ++w)
        for (int l = 0; l + w < N; ++l) {
            int r = l + w;
            for (int k = l; k < r; ++k) {
                dp[l][r] = min(dp[l][k] + dp[k+1][r] + (preSum[r + 1] - preSum[l]), dp[l][r]);
            }
        }
    cout << dp[0][N-1] << endl;
    return 0;
}