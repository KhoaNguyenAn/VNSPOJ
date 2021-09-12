#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
int a[300000],f[300000],g[300000],d[300000],n,mid,ans,j;
using namespace std;
const int inf = (1 << 31);

int bns(int l , int r , int v )
{
   while (l <= r)
   {
        mid = (l + r) / 2;
       if (g[mid] >= v)
       {
           r = mid - 1;
       }
       else l = mid + 1;
   }
   return r;
}

int main()
{
    cin >> n ;
    for (int i = 1; i<= n; i++)
    {
         cin >> a[i];
    }
    ans = 0;
    g[0] = inf;
    f[0] = 0;
    for (int i = 1; i<=n; i++)
    {
      j = bns(1,ans,a[i]);
      f[i] = j + 1;
      g[f[i]] = a[i];
      d[f[i]] = i;
      if (f[i] > ans) ans = f[i];
    }
    cout << ans;
}
