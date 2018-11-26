#include <iostream>
#include <string>

using namespace std;
const int MAXN = int(1e5+10);
int dp[MAXN][MAXN];
int solve(string &s, string &t) {
    int ss = s.size(), ts = t.size();
    // cout << ss << endl;
    // cout << ts << endl;
    int ans = -1;
    for (int i = 1; i <= ss; ++i)
        for (int j = 1; j <= ts; ++j) {
            if (s[i - 1] == t[j - 1])
                ans = dp[i - 1][j - 1] + 1;
            else
                ans = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = ans;
        }
    return dp[ss][ts];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n,m;
    cin >> n;
    string s, t;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> m;
        if (i < n)
            s += m + '0';
        else
            t += m + '0';
    }
    // cout << s << "\n" << t;
    // cin >> s >> t;
    cout << solve(s, t) << endl;
}