#include <iostream>
#include <algorithm>
using namespace std;


const int MAXN = 100;
int a[MAXN + 10], dp[MAXN][MAXN];
int preSum[MAXN + 10];
int p[MAXN][MAXN];
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
        p[i][i] = i;
    }
    for (int w = 1; w < N; ++w)
        for (int l = 0; l + w < N; ++l) {
            int r = l + w;
            for (int k = p[l][r-1]; k <= p[l+1][r]; ++k) {
                int tmp = dp[l][k] + dp[k+1][r] + (preSum[r + 1] - preSum[l]);
                if (dp[l][r] > tmp) {
                    dp[l][r] = tmp;
                    p[l][r] = k;
                }
            }
        }
    cout << dp[0][N-1] << endl;
    return 0;
}