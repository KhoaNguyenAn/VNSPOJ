#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#define INF 99999999
const int N = 1e3 + 2;
using namespace std;
int a[N][N],n,m,k,u,v,c,q,trace[N][N];
vector <int> d;
void trace_floyd(int l , int r)
{
    if (trace[l][r] == 0)
    {
        d.push_back(r);
        return;
    }
    trace_floyd(l,trace[l][r]);
    trace_floyd(trace[l][r],r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
       for (int j = 1; j <= n; j++)
            a[i][j] = INF;
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
    }
    for (int i = 1; i <= n; i++)
     for (int j = 1; j <= n ; j++)
        for (int k = 1; k <= n; k++)
         {
            if (a[j][k] > a[j][i] + a[i][k])
            {
                a[j][k] = a[j][i] + a[i][k];
                a[k][j] = a[j][k];
                trace[j][k] = i;
                trace[k][j] = i;
            }
         }
     for (int i = 1; i <= q; i++)
     {
         cin >> u >> v >> c;
         if (u == 0)
         {
               cout << a[v][c] << "\n";
         }
         if (u == 1)
         {
             if (a[u][v] == INF)
              cout << -1 << "\n";
             else
             {
             d.push_back(v);
             trace_floyd(v,c);
             cout << int(d.size()) << " ";
             for (int j = 0 ; j < int(d.size()); j++)
               cout << d[j] << " ";
             d.clear();
             cout << "\n";
             }
        }
     }
}
