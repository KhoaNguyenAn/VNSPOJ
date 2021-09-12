///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "PCBGANGS"
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
int n,m,u,v,p[N],thu[N];
char x;
int getroot(int x)
{
	 if (p[x] == 0) return x;
	 p[x] = getroot(p[x]);
	 return p[x];
}
void Union(int x,int y)
{
	 int xx = getroot(x);
	 int yy = getroot(y);
	 if (xx != yy) p[xx] = yy;
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
		while (m--)
		{
			 cin >> x >> u >> v;
			 if (x == 'F') Union(u,v);
			 else
			 {
			 	 if (thu[v]) Union(u,thu[v]);
			 	 if (thu[u]) Union(v,thu[u]);
			 	 thu[u] = v;
			 	 thu[v] = u;
			 }
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (getroot(i) == i) res++;
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/