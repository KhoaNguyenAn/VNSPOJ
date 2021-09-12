#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int N = 1e5;
vector <int> a[N];
int root,n,m,u,v,seen[N],num[N],low[N],edge = 0,bridge = 0,cnt = 0,AP[N];
void dfs(int u, int p)
{
    num[u] = low[u] = cnt++;
    seen[u] = true;
    int child = 0;
    for (int v = 0; v < a[u].size(); v++)
    if (seen[a[u][v]] == false)
    {
        child++;
        dfs(a[u][v],u);
        low[u] = min(low[u],low[a[u][v]]);
        if (u != root && num[u] <= low[a[u][v]])
            AP[u] = true;
        if (num[u] < low[a[u][v]]) bridge++;
    }
    else if (a[u][v] != p) low[u] = min(low[u],num[a[u][v]]);
    if (child > 1 && u == root) AP[u] = true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    fill(seen+1,seen+n+1,false);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        root = i;
        dfs(root,0);
    }
    for (int i = 1; i <= n; i++)
        if (AP[i]==true) edge++;
    cout << edge << " " << bridge;
    return 0;
}
