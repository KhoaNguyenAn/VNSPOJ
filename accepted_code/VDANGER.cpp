#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1e4 + 5;
long long n,m,a[N],f[N][N],ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> f[i][j];
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= n; j++)
          for (int k = 1; k <= n; k++)
             f[j][k] = min(f[j][i]+f[i][k],f[j][k]);
    ans = 0;
    for (int i = 2; i <= m; i++)
       ans += f[a[i-1]][a[i]];
    cout << ans;
}
