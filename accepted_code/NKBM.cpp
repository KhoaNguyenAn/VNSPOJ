#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N = 1e3+5;
int match[2][N];
bool seen[N];
vector <int> a[N];
bool dfs(int u)
{
		for (int v = 0; v < a[u].size(); v++)
		{
		int yy = a[u][v];
		int xx = u;
		if (seen[yy]==0)
		{
				seen[yy] = 1;
				if (match[1][yy]==-1)
				{
					  match[0][xx] = yy;
					  match[1][yy] = xx;
					  return true;
				}
				else if (dfs(match[1][yy]))
				{
						match[0][xx] = yy;
						match[1][yy] = xx;
						return true;
				}
		}
		}
		return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
		int x,y,m,u,v,ans;
		cin >> x >> y >> m;
		for (int i = 1; i <= m; i++)
		{
				cin >> u >> v;
				a[u].push_back(v);
		}
		memset(match,-1,sizeof(match));
		while (1)
		{
				bool ok = 0;
				memset(seen,false,sizeof seen);
				for (int i = 1; i <= x; i++)
					if (match[0][i]==-1 && dfs(i))
					{
						 ok = 1;
						 break;
					}
			  if (!ok) break;
		}
		ans = 0;
		for (int i = 1; i <= x; i++)
			if (match[0][i]!=-1) ans++;
		cout << ans;
    return 0;
}
