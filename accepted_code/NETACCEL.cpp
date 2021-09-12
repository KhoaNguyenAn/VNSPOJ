//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "NETACCEL"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, long double> ii;
typedef pair <ll, ii> iii;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 10;
const long double INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long double d[N][11];
vector <ii> a[N];
int n,m,k,u,v;
long double t;
struct data
{
	  int u,i;
	  long double c;
	  bool operator < (const data &o) const
	  {
				return (c - o.c > 0.001);
	  }
};
inline void Dijiska()
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
	 	   long double c = tmp.c;
	 	   if (c - d[u][i] > 0.001) continue;
	 	   for (auto v: a[u])
			 {
			 	for (int j = 0; j <= k; j++)
				{
					if (d[v.X][j] - (d[u][j] + v.Y)>0.001)
					{
						  d[v.X][j] = d[u][j] + v.Y;
						  heap.push({v.X,j,d[v.X][j]});
					}
			if (i+j <= k && d[v.X][i+j]-(d[u][i]+(v.Y/(long double)(1<<(j))))>0.001)
					{
						 d[v.X][i+j] = d[u][i]+((v.Y)/(long double)(1<<(j)));
						 heap.push({v.X,i+j,d[v.X][i+j]});
					}
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
			 cin >> u >> v >> t;
			 a[u].push_back(ii(v,t));
			 a[v].push_back(ii(u,t));
		}
		Dijiska();
		long double ans = INF64;
		for (int i = 0; i <= k; i++)
		 if (ans - d[n][i] > 0.001) ans = d[n][i];
		cout << setprecision(2) << fixed << ans;
		return 0;
}
/**Code written by AnkhoaGD**/


