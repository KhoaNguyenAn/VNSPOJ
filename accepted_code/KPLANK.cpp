#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
ll stk[N],l[N],r[N],top,n,a[N];
int main()
{
     ios_base :: sync_with_stdio(0);
     cin.tie(0);
     cin >> n;
     for (int i = 1; i <=n ; i++)
     {
         cin >> a[i];
     }
     stk[0] = 0;
     top = 0;
     for (int i = 1; i <= n ; i++)
     {
         while (a[stk[top]] >= a[i])
             {
                top--;
             }
             l[i] = stk[top] + 1;
             top++;
             stk[top] = i;
     }

    // VE PHAI

    stk[0] = n+1;
     top = 0;
     for (int i = n; i >= 1 ; i--)
     {
         while (a[stk[top]] >= a[i])
             {
                top--;
             }
             r[i] = stk[top] - 1;
             top++;
             stk[top] = i;
     }
     ll dt;
     ll mmax = 0;
     for (int i =1;i<=n;i++)
     {
     if (a[i] <= r[i] - l[i] + 1)
      if (mmax < a[i]) mmax = a[i];
     }
     cout << mmax;
}
