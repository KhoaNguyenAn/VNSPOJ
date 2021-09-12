///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "CRITICAL"
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
const ll N = 2e5 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int TPLT[N],label[N],g[N],num[N],low[N],cnt = 0,n,m,u,v,sl;
long long res;
bool seen[N];
vector <int> a[N];
void count_child(int u)
{
	  seen[u] = true;
	  TPLT[sl]++;
	  label[u] = sl;
	  g[u] = 1;
	  for (int v: a[u])
		if (seen[v] == false)
		{
			 count_child(v);
			 g[u]+=g[v];
		}
}
void DFS(int u,int p)
{
	  num[u] = low[u] = ++cnt;
	  int child = 0;
	  vector <int> Edge;
	  for (int v: a[u])
		if (v != p)
		{
			 if (num[v]) low[u] = min(low[u],num[v]);
			 else
			 {
			 	  DFS(v,u);
			 	  child++;
			 	  low[u] = min(low[u],low[v]);
			 	  if (num[u] <= low[v]) Edge.push_back(g[v]);
			 }
		}
    if (!Edge.empty())
		{
			long long sum = 0;
			for (int x : Edge) sum+=x;
			Edge.push_back(TPLT[label[u]]-1-sum);
			res+= (TPLT[label[u]]-1) * (TPLT[label[u]]-1);;
			for (int x : Edge) res -= x*x;
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
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			  cin >> u >> v;
			  a[u].push_back(v);
			  a[v].push_back(u);
		}
		memset(seen,false,sizeof seen);
		sl = 0;
		res = 0;
		for (int i = 1; i <= n; i++)
		if (seen[i] == false)
		{
			 sl++;
			 count_child(i);
			 DFS(i,i);
		}
		cout << setprecision(2) << fixed <<((long double)(res/2))/n;
		return 0;
}
/**Code written by AnkhoaGD**/