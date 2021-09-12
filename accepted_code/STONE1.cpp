#include <bits/stdc++.h>
#include <iostream>
#define taskname "STONE1"
#define X first
#define Y second
#define MOD 1000000007ll
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e4 + 5;
const ll INF = 1e9 + 10;
/*** To break barriers
		 To reach for the star
		 To make the unknown known
		 To make the ordinary extraodinary
		 To make the greater greater
***/
ll dp[N],n,m,u,v,V[N];
bool seen[N];
vector <int> a[N];
void dfs(int u)
{
	 seen[u] = true;
	 if (a[u].empty())
	 {
	 	  dp[u] = 1;
	 	  return;
	 }
	 for (int i = 0 ; i < a[u].size(); i++)
	 if (seen[a[u][i]] == false)
	 	  dfs(a[u][i]);
	 for (int i = 0 ; i < a[u].size(); i++) V[i] = dp[a[u][i]];
	 sort(V,V+a[u].size(),greater<int>());
	 ll res = 0;
	 for (int i = 0; i < a[u].size(); i++) res = max(res,i+V[i]);
	 dp[u] = res;
}
inline void solve()
{
	 memset(seen,false, sizeof seen);
	 dfs(1);
	 cout << dp[1];
}
inline void init()
{
	 cin >> n;
	 while (cin >> u)
	 {
	 	  cin >> m;
	 	  for (int i = 1; i <= m; i++)
			{
				 cin >> v;
				 a[u].push_back(v);
			}
	 }
}
/************** [MAIN] **************/
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		init();
		solve();
		return 0;

}



/**********************************************
*	Code written by Kaze1402							 ||*
*||	NguyenAnKhoa, #GD high school HCM_VN	 ||*
**********************************************/
/** _"You said you worked hard? Well, maybe you need to work a little longer"_**/



