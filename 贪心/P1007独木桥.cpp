#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    freopen("input.txt", "r", stdin);
    int L, N, a[5010];
    scanf("%d%d", &L, &N);
    for (int i=0; i<N; i++)
        scanf("%d", &a[i]);
    int min_t = 0, max_t = 0;
    for (int i=0; i<N; i++)
    {
        min_t = max(min_t, min(a[i], L+1-a[i]));
        max_t = max(max_t, max(a[i], L+1-a[i]));
    }
    printf("%d %d\n", min_t, max_t);
    return 0;
}