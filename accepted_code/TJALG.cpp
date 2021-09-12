#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
const int N = 1e4+5;
queue <int> que;
int n,m,u,v,res,num[N],low[N],seen[N],cnt = 0;
vector <int> a[N];
void dfs(int x)
{
	que.push(x);
	num[x] = low[x] = ++cnt;
	seen[x] = 1;
	for (int v = 0; v < a[x].size(); v++)
	{
		int y = a[x][v];
		if (seen[y] == 2) continue;
		if (seen[y] == 1) low[x] = min(low[x],num[y]);
		if (seen[y] == 0)
		{
			dfs(y);
			low[x] = min(low[x],low[y]);
		}
	}
	if (low[x] >= num[x])
	{
		res++;
		/*while (que.front() != x)
		{
			seen[que.front()] = 1;
			que.pop();
		}
		que.pop();*/
		seen[x] = 2;
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
		cin >> u >> v;
		a[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
	if (seen[i] == 0) dfs(i);
	cout << res;
    return 0;
}
