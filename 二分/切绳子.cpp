#include <iostream>
#include <cstdio>
using namespace std;

int N, K;
int a[10010];

int judge(int m)
{
    int cnt = 0;
    for (int i=0; i<N; i++)
    {
        cnt += a[i] / m;
    }
    if (cnt >= K) return 1;
    return 0;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int l=0, r=-1;
    double inp;
    scanf("%d%d",&N,&K);
    for (int i=0;i<N;i++)
    {
        scanf("%lf",&inp);
        a[i] = int(inp * 100000);
        r = max(r, a[i]);
    }
    while(l<r)
    {
        double m = l + ((r - l) >> 1);
        if (judge(m))
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    printf("%.2lf", (l-1)/100000.0);
    return 0;
}