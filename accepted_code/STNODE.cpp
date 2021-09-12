#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
const int N = 1e5 + 2;
bool kt = false,seen[N];
vector <int> a[N],trace;
int n,m,s,t,u,v,par[N],pos[N],r,res;
void dfs(int u)
{
		seen[u] = true;
		for (int v = 0; v < a[u].size(); v++)
		if (seen[a[u][v]]==false)
		{
				par[a[u][v]] = u;
				dfs(a[u][v]);
		}
}
int bfs(int u)
{
		queue <int> que;
		que.push(u);
		seen[u] = true;
		int ok = -1;
		while (!que.empty())
		{
			 int v = que.front();
			 que.pop();
			 for (int j = 0; j < a[v].size(); j++)
		   if (seen[a[v][j]] == false && pos[a[v][j]] < 0)
		   {
					seen[a[v][j]] = true;
					que.push(a[v][j]);
		   }
		   else ok = max(ok,pos[a[v][j]]);
		}
		return ok;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
		{
				cin >> u >> v;
				a[u].push_back(v);
		}
		fill(seen+1,seen+n+1,false);
		dfs(s);
		int j = t;
		while (par[j]!=s)
		{
				trace.push_back(j);
				j = par[j];
		}
		trace.push_back(j);
		trace.push_back(s);
		reverse(trace.begin(),trace.end());
		int r = -1;
		res = 0;
		fill(seen+1,seen+n+1,false);
		fill(pos+1,pos+n+1,-1);
		for (int i = 0;i < trace.size();i++) pos[trace[i]] = i;
		for (int i = 0;i < trace.size(); i++)
		{
				if (trace[i]!=s && trace[i]!=t && r <= pos[trace[i]]) res++;
				r = max(r,bfs(trace[i]));
		}
		cout << res;
    return 0;
}
