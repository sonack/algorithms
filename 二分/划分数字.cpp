// 洛谷 P1182
// 数列分段
#include <iostream>
#include <cstdio>
using namespace std;
int N, M;
int a[100010]; 

int judge(int x)
{
    int i=0;
    int cur_sum = 0;
    int part_cnt = 0;
    while(i<N)
    {   
        if (a[i] > x) return 0;
        cur_sum += a[i++];
        if (cur_sum > x)
        {
            i--;
            cur_sum = 0;
            part_cnt++;
        }
    }

    // 如果不为0， 则说明最后一段开始了新的，还未结束
    if (cur_sum)
        part_cnt++;
    if (part_cnt > M)
        return 0;
    return 1;
}
int main()
{
    // freopen("input.txt","r",stdin);
    scanf("%d%d", &N, &M);
    int l = -1, r = 0;
    for (int i=0;i<N;i++)
    {
        scanf("%d", &a[i]);
        r += a[i];
        l = max(l, a[i]);
    }
    r++;
    while(l < r)
    {
        int m = l + ((r - l) >> 1);
        if (judge(m))
        {
            r = m;
        }
        else
        {
            l = m+1;
        }

    }
    printf ("%d", l);
    return 0;
}