#include <iostream>
#include <cstdio>
#include <set>
#define LL long long 
using namespace std;

int a[100010];
int main()
{
    // freopen("input.txt", "r", stdin);
    int T;
    int n, k;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        multiset<int> s;
        LL cnt = 0;
        for (int l = 0, r = 0; l < n; l++)
        {
            while (r < n && (!s.size() || (a[r] - *s.begin() < k && *s.rbegin() - a[r] < k)))
            {
                s.insert(a[r++]);
            }

            // printf ("min = %d, max = %d", *s.begin(), *s.rbegin());
            cnt += r - l;
            s.erase(s.find(a[l]));
        }
        printf ("%lld\n", cnt);
    }
    return 0;
}