//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "PWALK"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1000 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long h[N],u,v,c,L,R,Q,n;
vector <ii> a[N];
void DFS(int u,int par)
{
	  for (auto v:a[u])
		if (v.X != par)
	  {
	  	  h[v.X] = h[u]+v.Y;
	  	  if (v.X == R) return;
	  	  DFS(v.X,u);
	  	  h[v.X] = 0;
	  }
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n >> Q;
		for (int i = 1; i <= n-1; i++)
		{
			  cin >> u >> v >> c;
			  a[u].push_back(ii(v,c));
			  a[v].push_back(ii(u,c));
		}
		while (Q--)
		{
			  cin >> L >> R;
			  DFS(L,-1);
			  cout << h[R] << endl;
			  h[R] = 0;
		}
		return 0;

}
/**Code written by AnkhoaGD**/


