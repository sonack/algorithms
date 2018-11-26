#include <iostream>
#include <cstdio>
using namespace std;

int K, N, a[300010], presum[300010];

// NlogN
int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &K);
    presum[0] = 0;
    for (int i=0; i<N; i++)
    {
        scanf("%d", &a[i]);
        presum[i+1] = a[i] + presum[i];
    }

    int ans = -1, ans_l;
    for (int L = 0; L < N; ++L)
    {
        int r = N, l = L;
        while(l < r)
        {
            int m = l + (r - l) / 2;
            if (m - L + 1 - (presum[m+1] - presum[L]) <= K)
                l = m + 1;
            else
                r = m;
        }
        if (r - L > ans)
        {
            ans = r - L;
            ans_l = L;
        }

    }
    printf ("%d\n", ans);
    for (int i=0;i<N;i++)
    {
        // printf ("i=%d ", i);
        if (i >= ans_l && i < ans + ans_l)
            printf ("%d", 1);
        else
            printf ("%d", a[i]);
        printf ("%c", i==N-1?'\n':' ');
    }
    return 0;
}

// O(N)
int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; i++)
    {
        scanf("%d", &a[i]);
    }
    int zeros = 0;
    pair<int, int> ans = make_pair(0, 0);
    for (int l = 0, r = 0; l < N; ++l)
    {
        // printf ("l=%d\n", l);
        // printf ("zeros=%d\n", zeros);
        // printf ("r=%d\n", r);
        while(r < N && (zeros + (a[r] == 0)) <= K) 
        {
            zeros += (a[r] == 0);
            r++;
        }
        ans = max(ans, make_pair(r-l, l));
        zeros -= a[l] == 0;
    }
    printf ("%d\n", ans.first);
    for (int i=0;i<N;i++)
    {
        // printf ("i=%d ", i);
        if (i >= ans.second && i < ans.first + ans.second)
            printf ("%d", 1);
        else
            printf ("%d", a[i]);
        printf ("%c", i==N-1?'\n':' ');
    }
    // printf ("%d %d", ans.second, ans.first+ans.second-1);
    return 0;
}

