#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,f[305][305],res,a[305];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
         cin >> a[i];
    res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(f,0,sizeof(f));
        for (int j = 1; j <= i ; j++)
          for (int k = i+1; k <= n; k++)
            if (a[j] < a[k]) f[j][k] = f[j-1][k-1] + 1; else f[j][k] = max(f[j-1][k],f[j][k-1]);
        res = max(res,f[i][n]);
    }
    cout << res;
    return 0;
}
