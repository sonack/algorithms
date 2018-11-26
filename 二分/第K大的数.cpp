#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long

const int maxn = 5e4;
int n, K;
LL a[maxn+10], b[maxn+10];

int judge(LL x)
{
    int cnt = 0;
    for (int i = 0, j = n - 1; i < n; i++)
    {
        for (; j >= 0 && a[i] * b[j] > x; j--);
        cnt += n - 1 - j;
    }
    return cnt;
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &K);
    for(int i = 0; i < n; i++)
        scanf("%lld%lld", &a[i], &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    LL l = 0, r = 1e18;
    while (l < r)
    {
        LL m = l + (r - l) / 2;
        if (judge(m) >= K)
            l = m + 1;
        else
            r = m;
    }
    printf("%lld", l);
    return 0;
}