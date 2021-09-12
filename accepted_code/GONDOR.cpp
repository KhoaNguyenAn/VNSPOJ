///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "GONDOR"
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
const ll N = 200 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long double d[N],x[N],y[N];
long long n,s[N];
int seen[N];
vector <int> a[N];
struct data
{
	  int u;
	  long double cost;
	  data() {};
	  data(int uu,long double c)
	  {
	  	 u = uu;
	  	 cost = c;
	  }
	  bool operator < (const data &C) const
	  {
	  	 return cost > C.cost;
	  }
};
long double dis(int uu,int vv)
{
	  long double X = x[uu]-x[vv];
	  long double Y = y[uu]-y[vv];
	  return sqrt(X*X+Y*Y);
}
void Dijiska()
{
	  fill(d+1,d+n+1,INF64);
	  memset(seen,0,sizeof seen);
	  d[1] = 0.00;
	  seen[1] = 1;
	  priority_queue <data> heap;
	  heap.push(data(1,0.00));
	  while (!heap.empty())
	  {
	  	 int u = heap.top().u;
			 long double C = heap.top().cost;
			 heap.pop();
			 if (C > d[u]) continue;
			 int cnt = 0;
			 seen[u] = 1;
			 for (int v: a[u])
			 {
			 	  if (cnt == s[u]) break;
			 	  if (seen[v] == 1) continue;
			 	  cnt++;
			 	  if (d[v] > d[u]+dis(u,v))
					{
						  d[v] = d[u]+dis(u,v);
						  heap.push(data(v,d[v]));
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
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			 cin >> x[i] >> y[i] >> s[i];
			 for (int j = 1; j <= n-1; j++)
			 {  int v;
			 	  cin >> v;
			 	  a[i].push_back(v);
			 }
		}
		Dijiska();
		for (int i = 1; i <= n; i++)
			cout << setprecision(6) << fixed << d[i] << endl;
		return 0;
}
/**Code written by AnkhoaGD**/