#include <iostream>
#include <cstdio>
#define MOD 10086 
using namespace std;
// 4 1 1 
// 
int N, a[10005];
int main()
{
    freopen("input.txt", "r", stdin);
    while (~scanf("%d", &N))
    {
        a[0] = a[N+1] = 21;
        for (int i = 1; i <= N; i++)
            scanf("%d", &a[i]);
        if (N > 1)
        {
            for (int i = 1; i <= N; i++)
            {
                if (a[i] == 1)
                {
                    if(a[i-1] <= a[i+1] || (a[i-1] == 2 && a[i+1] == 1))
                    {
                        a[i] += a[i-1];
                        a[i-1] = 1;
                    }
                    else
                    {
                        a[i+1] += a[i];
                        i++;
                    }
                }
            }
        }
        for (int i = 2; i <= N; i++)
            a[1] = (a[1] * a[i]) % MOD;
        printf("%d\n", a[1]);
    }
    return 0;
}
