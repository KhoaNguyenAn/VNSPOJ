#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N = 5005;
string st[N];
unsigned long long n,m,f[N][N],res,l[N][N],r[N][N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("NKCNT.out","r",stdin);
    /*cout << 5000 << " " <<  5000 << "\n";
    for (int i = 1; i <= 5000; i++)
    {
     for (int j = 1; j <= 5000; j++)
        cout << 0;
        cout << "\n";
    }*/

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> st[i];
    for (int i = 1; i <= n; i++)
     for (int j = 1; j <= m; j++)
        if (st[i][j-1] == '0')
        {
            l[i][j] = l[i][j-1] + 1;
            r[i][j] = r[i-1][j] + 1;
        } else
        {
            l[i][j] = 0;
            r[i][j] = 0;
        }
    res = 0;
    for (int i = 1; i <= n ;i++)
     for (int j = 1; j <= m; j++)
     {
        f[i][j] = min(min(l[i][j],r[i][j]),f[i-1][j-1]+1);
        res+=f[i][j];
     }
     cout << res;
    return 0;
}
