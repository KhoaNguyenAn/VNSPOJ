#include <iostream>
#include <bits/stdc++.h>
#define INF 999
using namespace std;
const int N = 1e2+5;
int n,m,f[N][N],a[N][N],ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n+1; i++)
     for (int j = 0 ; j <= m+1; j++)
        f[i][j] = -INF;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         cin >> a[i][j];
    for (int i = 1; i <= n ; i++) f[i][1] = a[i][1];
    for (int j = 2; j <= m; j++)
      for (int i = 1; i <= n ; i++)
        f[i][j] = max(max(f[i][j-1],f[i-1][j-1]),f[i+1][j-1]) + a[i][j];
    ans = -INF * 10004;
    for (int i = 1; i <= n; i++) ans = max(ans,f[i][m]);
    cout << ans;
    return 0;
}
/*5 7
9 -2 6 2 1 3 4
0 -1 6 7 1 3 3
8 -2 8 2 5 3 2
1 -1 6 2 1 6 1
7 -2 6 2 1 3 7*/
