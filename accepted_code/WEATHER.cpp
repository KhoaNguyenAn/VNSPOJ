#include <iostream>
#include <math.h>
#include <vector>
#include <bits/algorithmfwd.h>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>

#define ll long long;
const int N = 1e3 + 7;
using namespace std;
int ans,a[105][105],seen[105],d[105],n,m,num[105],low[105];
int dfscnt = 0;
void dem(int u)
{
    seen[u] = true;
    for (int i = 1; i <= n; i++)
        if (a[u][i]==true && seen[i] == false)
        {
            dem(i);
            d[u]=d[u]+d[i]+1;
        }
}

void dfs(int u , int p)
{
    num[u] = low[u] = dfscnt++;
    seen[u] = true;
    for (int v = 1; v <= n; v++)
    if (a[u][v])
    {
        if (seen[v] == false)
        {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if (num[u] < low[v]) ans+=(d[v]+1)*(n-d[v]-1);
        }
        else if (v != p) low[u] = min(low[u],num[v]);
    }
}

int main()
{
    cin >> n >> m;
    int u,v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v] = a[v][u] = true;
    }
    fill(seen+1,seen+n+1,false);
    dem(1);
    fill(seen+1,seen+n+1,false);
    ans = 0;
    dfs(1,0);
    cout << ans;
}
