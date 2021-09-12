#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <vector>
using namespace std;
const int N = 2 * 1e5 +7;
typedef pair <int,int> ii;
#define X first
#define Y second
int n,u,v,m,seen[N],cnt,bridges,num[N],low[N];
vector <ii> a[N];
void dfs(int u , int p)
{
    num[u] = low[u] = cnt++;
    seen[u] = true;
    for (int v = 0; v < int(a[u].size()); v++)
    {
        ii tmp = a[u][v];
        if (seen[tmp.Y] == false)
        {
            dfs(tmp.Y,tmp.X);
            low[u] = min(low[u],low[tmp.Y]);
            if (num[u] < low[tmp.Y]) bridges++;
        }
        else if (tmp.X != p) low[u] = min(low[u],num[tmp.Y]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> u >> v;
        a[u].push_back(ii(i,v));
        a[v].push_back(ii(i,u));
    }
    cin >> m;
    for (int i = n; i < m+n; i++)
    {
        cin >> u >> v;
        a[u].push_back(ii(i,v));
        a[v].push_back(ii(i,u));
    }
    cnt = 0;
    fill(seen+1,seen+n+1,false);
    dfs(1,0);
    cout << bridges;
}
