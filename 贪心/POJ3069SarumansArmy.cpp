#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int N, R;
int a[1010];
int main()
{
    // freopen("input.txt", "r", stdin);
    while(1)
    {
        scanf("%d%d", &R, &N);
        if (N==-1) break;
        for(int i = 0; i < N; i++)
            scanf("%d", &a[i]);
        sort(a, a+N);
        int last = 0, i = 0;
        int cnt = 0;
        // int j = 1;
        // for(int i = 1; i < N; i++)
        // {
        //     if (a[i] == a[i-1])
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         a[j++] = a[i];
        //     }
        // }
        // N = j;

        // for(int i = 0; i < N; i++)
        //     printf ("%d ", a[i]);
        // printf ("\n");
        
      
        // while (i < N)
        // {
        //     int s = a[i++];
        //     while (i < N && a[i] - s <= R) i++;
        //     int p = a[i-1];
        //     cnt++;
        //     while (i < N && a[i] - p <= R) i++;
        // }


        while(i < N && a[i] - a[0] <= R) i++;
        cnt++;
        last = i - 1;

        while (i < N)
        {
            while (i < N && a[i] - a[last] <= R) i++;
            if (i < N)
            {
                last = i++;  // 未被覆盖的点


                while (i < N && a[i] - a[last] <= R) i++;
                last = i - 1; // 覆盖点
                cnt++;

            }          
        }
        printf ("%d\n", cnt);
    }
    return 0;
}
