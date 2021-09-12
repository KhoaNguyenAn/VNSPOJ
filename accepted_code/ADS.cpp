///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "ADS"
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
int n,m;
vector <int> a[N];
bool seen[N];
void DFS(int u)
{
	 seen[u] = true;
	 for (auto v:a[u])
	 if (seen[v] == false) DFS(v);
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
			 static int u,v;
			 cin >> u >> v;
			 a[u].push_back(v);
			 a[v].push_back(u);
		}
		int k = 0;
		memset(seen,false,sizeof seen);
		for (int i = 1; i <= n; i++)
		if (seen[i] == false) DFS(i),k++;
		cout << m-n+k;
		return 0;
}
/**Code written by AnkhoaGD**/