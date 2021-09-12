//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "REVAMP"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1e5 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long n,m,k,u,v,c;
long long d[N][30];
vector <ii> a[N];
struct data
{
	  int u,i;
	  long long c;
	  bool operator < (data const &o) const
	  {
	  	 return c > o.c;
	  }
};
void Dijiska()
{
	 for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++) d[i][j] = INF64;
	 priority_queue <data> heap;
	 d[1][0] = 0;
	 heap.push({1,0,0});
	 while (!heap.empty())
	 {
	 	  data tmp = heap.top();
	 	  heap.pop();
	 	  int u = tmp.u;
	 	  int i = tmp.i;
	 	  int c = tmp.c;
	 	  if (c > d[u][i]) continue;
	 	  for (auto v: a[u])
	 	  {
	 	  	 if (d[v.X][i] > d[u][i]+v.Y)
				 {
				 	   d[v.X][i] = d[u][i]+v.Y;
						 heap.push({v.X,i,d[v.X][i]});
				 }
				 if (i < k && d[v.X][i+1] > d[u][i])
				 {
				    d[v.X][i+1] = d[u][i];
				    heap.push({v.X,i+1,d[v.X][i+1]});
				 }
	 	  }
	 }
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n >> m >> k;
		while (m--)
		{
			 cin >> u >> v >> c;
			 a[u].push_back(ii(v,c));
			 a[v].push_back(ii(u,c));
		}
		Dijiska();
		long long ans = INF64;
		for (int i = 1; i <= k; i++) ans = min(ans,d[n][i]);
		cout << ans;
		return 0;
}
/**Code written by AnkhoaGD**/


