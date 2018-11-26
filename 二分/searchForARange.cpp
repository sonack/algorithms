#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int lower_bound(int *A, int N, int T)
{
    int l=0, r=N;
    while(l<r)
    {
        int m = l + (r - l) / 2;
        if (A[m] < T)
            l = m + 1;
        else
            r = m;
    }
    return l;
}

int upper_bound(int *A, int N, int T)
{
    int l=0, r=N;
    while(l<r)
    {
        int m = l + (r - l) / 2;
        if (A[m] <= T)
            l = m + 1; 
        else
            r = m;
    }
    return l;
}


// return the first element which >= x
int LowerBound(int *a, int n, int x)
{
  int left(0), right(n-1), mid;
  
  while(left <= right){
    mid = left + ((right - left) >> 1);
    if(a[mid] < x){
        left = mid + 1;
    }
    else{
        right = mid - 1;
    }
  }
  printf ("l=%d, r=%d",left, right);
 
  return left;
}
 
// return first element which > x
int UpperBound(int *a, int n, int x)
{
  int left(0), right(n-1), mid;
 
  while(left <= right){
      mid = left + ((right - left) >> 1);
      if(a[mid] <= x){
          left = mid + 1;
      }
      else{
          right = mid - 1;
      }
  }

  printf ("l=%d, r=%d", left, right);
  return left;
}


int main()
{
    freopen("input.txt", "r", stdin);
    int a[100],N,T;
    scanf("%d%d", &N, &T);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a,a+N);

    // int lb = lower_bound(a, N, T);
    // int ub = upper_bound(a, N, T);

    int lb = LowerBound(a, N, T);
    int ub = UpperBound(a, N, T);

    printf("%d-%d\n", lb, ub);
    return 0;
}