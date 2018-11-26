// 洛谷 P1090 https://www.luogu.org/problemnew/show/P1090
#include <iostream>
#include <algorithm>
#include <queue>
// #include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN = 1e5;
int fruits[MAXN + 10];
priority_queue<int, vector<int>, greater<int> > Q;
int main()
{
    freopen("input.txt", "r", stdin);
    int T, N, tmp1, tmp2;
    // cin >> T;
    T = 1;
    while(T--) {
        LL ans = 0;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> fruits[i];
            Q.push(fruits[i]);
        }
        sort(fruits, fruits + N);
        for (int i = 0; i < N - 1; ++i) {
            tmp1 = Q.top(); Q.pop();
            tmp2 = Q.top(); Q.pop();
            ans += (tmp1 + tmp2);
            Q.push(tmp1 + tmp2);
        }
        // for (int i = 0; i < N - 1; ++i) {
        //     LL tmp = (fruits[i + 1] += fruits[i]);
        //     ans += tmp;
        //     int j;
        //     for (j = i + 2; j < N && fruits[j] < tmp; ++j) {
        //         fruits[j - 1] = fruits[j];
        //     }
        //     fruits[j - 1] = tmp;
        // }
        cout << ans << endl;
    }
    return 0;
}