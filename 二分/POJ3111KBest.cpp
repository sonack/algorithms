#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int N, K;
struct jewels
{
    int id;
    int v;
    int w;
    double comp_key;
}J[100010];

bool cmp(const jewels &l, const jewels &r)
{
    return l.comp_key > r.comp_key;
}
int judge(double x)
{
    for (int i = 0; i < N; i++)
        J[i].comp_key = J[i].v - J[i].w * x;
    double sum = 0;
    sort(J, J + N, cmp);
    for (int i = 0; i < K; i++)
        sum += J[i].comp_key;
    return sum >= 0;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
    {   
        scanf("%d%d", &J[i].v, &J[i].w);
        J[i].id = i+1;
    }
    double l = 0, r = 1e8;
    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if (judge(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    // printf ("%.2f\n", l);
    for (int i = 0; i < K; i++)
        printf ("%d%c", J[i].id, i < K - 1 ? ' ' : '\n');
    return 0;

}