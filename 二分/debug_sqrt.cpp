#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// int mySqrt(int x) {
//         int l = 1, r = x+1;
//         while(l<r)
//         {
//             int m = l + (r - l) / 2;
//             printf ("l=%d,m=%d,r=%d\n", l, m, r);
//             printf ("m*m=%d ",m*m);
//             printf ("x=%d\n", x);
//             if (x / m >= m)
//                 l = m + 1;
//             else
//                 r = m;
//         }
//         return l-1;
//     }



    int mySqrt(int x) {
        unsigned int l = 1, r = x+1;
        printf ("%d %d", l, r);
        while(l<r)
        {
            int m = l + (r - l) / 2;
               printf ("l=%d,m=%d,r=%d\n", l, m, r);
            // printf ("x/m"=%d ",m*m);
            // printf ("x=%d\n", x);
            if (m<=x/m)
                l = m + 1;
            else
                r = m;
        }
        return l-1;
    }

    

int main()
{
    printf("%d", mySqrt(2147483647));
    return 0;
}