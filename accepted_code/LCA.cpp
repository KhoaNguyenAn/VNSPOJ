#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int N = 1e3 +5;
vector <int> a[N];
int seen[N],par[N][15],u,d[N],m,n,tmp,v,q,x,y,root[N];
void dfs(int u)
{
	seen[u] = 1;
	for (int i2 = 1; i2 <= a[u].size();i2++)
		if (seen[a[u][i2-1]] == 0)
		{
			d[a[u][i2-1]] = d[u] + 1;
			par[a[u][i2-1]][0] = u;
			dfs(a[u][i2-1]);
		}
}

int LCA(int x, int y)
{
	if (d[x] < d[y]) swap(x,y);
	int tam = d[x] - d[y];
	for (int i1 = 0; tam > 0; i1++,tam >>=1)
	  if (tam & 1) // tam mod 2 <> 0
	  	x = par[x][i1];
	if (x == y) return x;
	for (int i1 = log2(m); i1 >= 0; i1--)
		if (par[x][i1] != par[y][i1])
		{
            x = par[x][i1];
            y = par[y][i1];
		}
	x = par[x][0];
	y = par[y][0];
	return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
    	cin >> m;
    	for (int j = 1; j <= m; j++)
    	{
    		cin >> tmp;
            for (int k = 1; k <= tmp; k++)
    		{
    			cin >> v;
    			a[j].push_back(v);
                root[v] = 1;
    		}
    	}
        for (int i4 = 1; i4 <= m; i4++)
          if (root[i4] == 0)
          {
              par[i4][0] = 0;
              dfs(i4);
          }
  		for (int j1 = 1; j1 <= log2(m); j1++)
				for (int i1 = 1; i1 <= m ; i1++)
					par[i1][j1] = par[par[i1][j1-1]][j1-1];
    	cin >> q;
    	cout << "Case "<< i << ":" << "\n";
    	for (int l = 1; l <= q; l++)
    	{
    		cin >> x >> y;
	   		cout << LCA(x,y) << "\n";
    	}
        fill(d+1,d+m+1,0);
        fill(seen+1,seen+m+1,0);
        fill(root+1,root+m+1,0);
        for (int i5 = 1; i5 <= m; i5++)
            a[i5].clear();
    }
}
