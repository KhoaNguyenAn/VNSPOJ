#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#define X first
#define Y second
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e5 +5 ;
typedef pair <int,int> ii;
vector <ii> a[N];
int seen[N],par[N][100],d[N],u,v,c,res1,res2,mmin[N][100],mmax[N][100],n,k;
void dfs(int u)
{
	seen[u] = 1;
	for (int i2 = 1; i2 <= a[u].size();i2++)
		if (seen[a[u][i2-1].X] == 0)
		{
			d[a[u][i2-1].X] = d[u] + 1;
			par[a[u][i2-1].X][0] = u;
			mmin[a[u][i2-1].X][0] = a[u][i2-1].Y;
			mmax[a[u][i2-1].X][0] = a[u][i2-1].Y;
			dfs(a[u][i2-1].X);
		}
}
int LCA(int x, int y)
{
	if (d[x] < d[y]) swap(x,y);
	int tam = d[x] - d[y];
	res1 = INF;
	res2 = 0;
	for (int i1 = 0; tam > 0; i1++,tam >>=1)
	  if (tam & 1) // tam mod 2 <> 0
		{
			res1 = min(res1,mmin[x][i1]);
			res2 = max(res2,mmax[x][i1]);
	  	x = par[x][i1];
		}
	if (x == y) return x;
	for (int i1 = log2(n); i1 >= 0; i1--)
		if (par[x][i1] != par[y][i1])
		{
            res1 = min(res1,min(mmin[x][i1],mmin[y][i1]));
            res2 = max(res2,max(mmax[x][i1],mmax[y][i1]));
            x = par[x][i1];
            y = par[y][i1];
		}
	res1 = min(res1,min(mmin[x][0],mmin[y][0]));
	res2 = max(res2,max(mmax[x][0],mmax[y][0]));
	x = par[x][0];
	y = par[y][0];
	return x;
}
int main()
{
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i < n; ++i)
    cin >> u >> v >> c,
    a[u].push_back({v, c}),
    a[v].push_back({u, c});
    par[1][0] = 0;
		dfs(1);
		for (int j1 = 1; j1 <= log2(n); j1++)
				for (int i1 = 1; i1 <= n; i1++)
					{
					  par[i1][j1] = par[par[i1][j1-1]][j1-1];
					  mmin[i1][j1] = min(mmin[i1][j1-1],mmin[par[i1][j1-1]][j1-1]);
					  mmax[i1][j1] = max(mmax[i1][j1-1],mmax[par[i1][j1-1]][j1-1]);
					}
		cin >> k;
		while (k--)
		{
			 cin >> u >> v;
			 LCA(u,v);
			 cout << res1 << " " << res2 << endl;
		}
		return 0;
}

