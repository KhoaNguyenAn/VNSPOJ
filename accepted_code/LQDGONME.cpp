#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define INF 9999
using namespace std;
const int N = 1e3+5;
bool seen[N];
int n,m,a[15][N],x,b[N][N],res = 1,f[N];
void dfs(int u)
{
		seen[u] = true;
		for (int v = 1; v <= n; v++)
			if (seen[v] == true && b[u][v] == true)
			{
					f[u] = max(f[v]+1,f[u]);
					res = max(res,f[u]);
			}
			else
			if (seen[v] == false && b[u][v] == true)
			{
					f[u] = max(f[v]+1,f[u]);
					dfs(v);
					f[u] = max(f[v]+1,f[u]);
					res = max(res,f[u]);
			}

}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
			  cin >> x;
			  a[i][x] = j;
			}
		}
	  for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
				if (i != j)
				{
						bool kt = true;
						for (int k = 1; k <= m ; k++)
					  if (a[k][i] > a[k][j])
					  {
								b[i][j] = false; kt = false;
								break;
					  }
					  if (kt == true) b[i][j] = true;
				}
		fill(seen,seen+N+1,false);
		fill(f,f+N+1,1);
		for (int i = 1; i <= n; i++)
		if (seen[i] == false)
		{
			dfs(i);
		}
		cout << res;
    return 0;
}
/*
4 3
1 2 3 4
1 4 2 3
1 2 4 3
*/