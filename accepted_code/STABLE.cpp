#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
typedef pair <ll,ll> ii;
#define INF 999999999999
#define X first
#define Y second
const int N = 1e4 + 3;
vector <int> a[N];
int ans[N],n,m,s,bac[N],v,u,seen[N][N];
queue <int> que;
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if (!seen[u][v])
				{
					seen[u][v] = 1;
					a[u].push_back(v);
				}
    }
    bac[s] = 1;
    que.push(s);
    while (!que.empty())
		{
			 u = que.front();
			 que.pop();
			 for (int i = 0; i < a[u].size();i++)
			 {
			 	   v = a[u][i];
			 	   if (!bac[v])
					 {
					 	   if (ans[u] == 1) ans[v] = 1;
					 	   bac[v] = bac[u]+1;
					 	   que.push(v);
					 }
					 else
					 if (bac[v] == bac[u]+1) ans[v] = 1;
			 }
		}
		int res =0;
		for (int i = 1; i <= n; i++) if (ans[i]) res++;
    cout << res;
    return 0;
}
