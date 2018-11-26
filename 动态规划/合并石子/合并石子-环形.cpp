#include <iostream>
#include <algorithm>
#include <cstring> // memset
using namespace std;


const int MAXN = 102 << 1;
int a[MAXN], dp[MAXN][MAXN], dp_max[MAXN][MAXN], preSum[MAXN];
int p[MAXN][MAXN];
//  p_max[MAXN][MAXN];
int main()
{
    freopen("input.txt", "r", stdin);
    int N0, N;
    cin >> N0;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < N0; ++i) {
        cin >> a[i];
        a[N0+i] = a[i];
    }
    N = 2 * N0 - 1;
    for (int i = 0; i < N; ++i) {
        preSum[i+1] = preSum[i] + a[i];
        dp[i][i] = 0;
        dp_max[i][i] = 0;
        p[i][i] = i;
        // p_max[i][i] = i;
    }
    // cout << N << endl;
    // for (int i = 0; i < N; ++i) {
    //     cout << a[i] << endl;
    // }
    for (int w = 1; w < N0; ++w)
        for (int l = 0; l + w < N; ++l) {
            int r = l + w;
            for (int k = p[l][r-1]; k <= p[l+1][r]; ++k) {
                int tmp = dp[l][k] + dp[k+1][r] + (preSum[r + 1] - preSum[l]);
                if (tmp < dp[l][r]) {
                    dp[l][r] = tmp;
                    p[l][r] = k;
                }
            }
            // max 不满足四边形不等式
            for (int k = l; k < r; ++k) {
                int tmp = dp_max[l][k] + dp_max[k+1][r] - (preSum[r + 1] - preSum[l]);
                if (tmp < dp_max[l][r]) {
                    dp_max[l][r] = tmp;
                    // p_max[l][r] = k;
                }
            }
        }
    int ans = dp[0][N0 - 1], ans_max = dp_max[0][N0 - 1];
    // int ans_s;
    for (int s = 1; s + N0 - 1 < N; ++s) {
        // if (dp[s][s + N0 - 1] < ans)
        // {
        //     ans = dp[s][s + N0 - 1];
        //     ans_s = s;
        // }
        ans = min(ans, dp[s][s + N0 - 1]);
        ans_max = max(ans_max, -dp_max[s][s + N0 - 1]);
    }
    cout << ans << endl;
    cout << ans_max << endl;
    // cout << ans_s << endl;
    return 0;
}