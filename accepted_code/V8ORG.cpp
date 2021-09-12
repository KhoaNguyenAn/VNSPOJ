///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "V8ORG"
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
int k,n,child[N],res = 0;
vector <int> a[N];
void DFS(int u)
{
	  if (a[u].size() == 0)
		{
			 child[u] = 1;
			 if (k == 1) res++,child[u] = 1;
			 return;
		}
	  child[u] = 1;
	  bool check = false;
	  for (auto v : a[u])
		{
			 DFS(v);
			 child[u]+=child[v];
		   if (child[v]+1 >= k || child[u] >= k) check = true;
		}
		if (check == true) res++,child[u] = 0;
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
		cin >> k;
		cin >> n;
		for (int i = 2; i <= n; i++)
		{  static int u;
			 cin >> u;
			 a[u].push_back(i);
		}
		DFS(1);
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/