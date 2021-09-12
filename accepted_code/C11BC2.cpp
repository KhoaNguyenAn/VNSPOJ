///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "C11BC2"
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
int n,m,u,v,k,p[N],s,t;
int getroot(int x)
{
	 if (p[x] == 0) return x;
	 p[x] = getroot(p[x]);
	 return p[x];
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
		for (int i = 2; i <= n; i++)
		{
			 cin >> v >> k;
			 int x = getroot(i);
			 int y = getroot(v);
			 if (k == 1 && x != y) p[x] = y;
		}
	  while (m--)
		{
			 cin >> s >> t;
			 cout << (getroot(s)!=getroot(t) ? "YES \n":"NO \n");
		}
		return 0;
}
/**Code written by AnkhoaGD**/