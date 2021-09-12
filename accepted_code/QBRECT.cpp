#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
int h[N][N] , a[N][N],m,n,b[N],stk[N],top,l[N],r[N];
int main()
{
    cin >> m >> n;
    int mmax = -1;
    for (int i = 1; i<= m; i++)
    {
       for (int j = 1; j<=n; j++)
       {
           cin >> a[i][j];
           if (a[i][j] == 1) h[i][j] = h[i-1][j] + 1; else h[i][j] = 0;
       }
       for (int j = 1; j <= n; j++) b[j] = h[i][j];
       fill(l+1,l+N,0);
       fill(r+1,r+N,0);
       stk[0] = 0;
       top = 0;
       b[0] = -1;
       b[n+1] = -1;
       for (int j = 1; j <= n ; j++)
       {
         while (b[stk[top]] >= b[j])
         {
             top--;
         }
         l[j] = stk[top] + 1;
         top++;
         stk[top] = j;
       }
       stk[0] = n+1;
       top = 0;
       b[0] = -1;
       b[n+1] = -1;
       for (int j = n ; j >= 1 ; j--)
       {
           while (b[stk[top]] >= b[j])
           {
               top--;
           }
           r[j] = stk[top] - 1;
           top++;
           stk[top] = j;
       }
       for (int j = 1; j <=n; j++)
       {
           int  kq = b[j]*(r[j]-l[j]+1);
           if (kq > mmax) mmax = kq;
       }
    }
    cout << mmax;
}
