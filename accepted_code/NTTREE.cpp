#include <bits/stdc++.h>
#include <iostream>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 3e5 + 5;
const ll INF = 1e9 + 7;

vector <ii> a[N];
ll child[N],d[N],e[N],f[N],ans,n,u,v,c;
bool seen[N];
void dfs(int u)
{
	  seen[u] = true;
	  for (int i = 0; i < a[u].size(); i++)
		{
			 ii v = a[u][i];
			 if (seen[v.X] == false)
			 {
			 	   dfs(v.X);
			 	   child[u]+= child[v.X]+1;
			 	   ans+=(child[v.X]+1)*(n-child[v.X]-1)*v.Y;
			 }
		}
}
int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n;
		for (int i = 1; i <= n-1; i++)
		{
			 cin >> u >> v >> c;
			 d[i] = u; e[i] = v; f[i] = c;
			 a[u].push_back(ii(v,c));
			 a[v].push_back(ii(u,c));
		}
		memset(seen,false,sizeof seen);
		dfs(0);
		cout << ans;
		return 0;
}