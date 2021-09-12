///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "PWRFAIL"
#define Eureka cerr << "Eureka"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1000 + 7;
const ll INF = 1e9 + 10;
const long double INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long n,W,x[N],y[N];
long double M;
vector <int> a[N];
long double dis(int u,int v)
{
	  long double X = x[u]-x[v];
	  long double Y = y[u]-y[v];
	  return sqrt(X*X + Y*Y);
}
long double c[N][N],d[N];
struct data
{
	  int u;
	  long double cost;
	  data() {};
	  data(int uu,int cc)
	  {
	  	  u = uu;
	  	  cost = cc;
	  }
	  bool operator < (const data &c) const
	  {
	  	 return cost > c.cost;
	  }
};
void Dijiska()
{
	  fill(d+1,d+n+1,INF64);
	  d[1] = 0.0;
	  priority_queue <data> heap;
	  heap.push(data(1,0.0));
	  while (!heap.empty())
		{
		  int u = heap.top().u;
		  long double C = heap.top().cost;
		  heap.pop();
		  if (C > d[u]) continue;
		  for (int k : a[u])
			{
				 if (d[k] > d[u] + c[u][k])
				 {
				 	  d[k] = d[u] + c[u][k];
				 	  heap.push(data(k,d[k]));
				 }
			}
		}
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 ///freopen(taskname".INP","r",stdin);
		 ///freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n >> W;
		cin >> M;
		for (int i = 1; i <= n; i++)
			 cin >> x[i] >> y[i];
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j < i; j++)
				 c[i][j] = INF64;
		for (int i = 1; i <= W; i++)
		{
			 int u,v;
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
			 c[u][v] = 0.0;
			 c[v][u] = 0.0;
		}
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j < i; j++)
		   if (c[i][j] == INF64 && dis(i,j) <= M)
			 {
			 	  a[i].push_back(j);
			 	  a[j].push_back(i);
			 	  c[i][j] = c[j][i] = dis(i,j);
			 }
	  Dijiska();
	  if (d[n] == INF64) cout << -1;
	  else cout << (long long) (d[n]*1000);
		return 0;
}
/**Code written by AnkhoaGD**/