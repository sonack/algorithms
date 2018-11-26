#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

double eps = 1e-4;
double interval_width = 1+eps;
double A,B,C,D;
double f(double x)
{
    return A*x*x*x+B*x*x+C*x+D;
}

double get_ans(double l, double r)
{
    // printf("(l=%lf, r=%lf)", l,r);
    if (f(l) * f(r) > 0)
        return 9999;
    while(r-l>eps)
    {
        double m = (l+r) / 2;
        if (f(m) * f(l) <=0)
            r = m;
        else
            l = m;
    }
    return (l+r)/2;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    vector<double> ans;
    double l = -100;
    scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
    while(l<100)
    {
        double solu = get_ans(l, l+interval_width);
        if (solu < 101)
        {
            ans.push_back(solu);
            // printf("%.2lf", solu);
        }

        l+=interval_width;
    }

    sort(ans.begin(), ans.end());

    for (int i=0;i<ans.size();i++)
        printf("%.2f ", ans[i]);
    return 0;
}