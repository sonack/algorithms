#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
struct act
{
    int begin, end;
}t[10010];

bool cmp(act &l, act &r)
{
    return (l.end < r.end) || (l.end == r.end && l.begin < r.begin);
}
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i=0;i<N;i++)
        scanf("%d%d", &t[i].begin, &t[i].end);
    sort(t, t+N, cmp);
    int last_time = -1, ans = 0;
    for (int i=0;i<N;i++)
    {
        if (t[i].begin >= last_time)
        {
            ans++;
            last_time = t[i].end;
        }
    }
    printf ("%d\n", ans);
    return 0;
}