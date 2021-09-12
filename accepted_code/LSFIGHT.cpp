///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "LSFIGHT"
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
const ll N = 500 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,a[N][N],f[N][N];
vector <int> ans;
int next(int x,int d)
{
	 if (x + d <= n) return x + d;
	 return (x + d) % n;
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
		 for (int j = 1; j <= n; j++) cin >> a[i][j];
		for (int i = 1; i <= n-1; i++) f[i][i+1] = 1;
		f[n][1] = 1;
		for (int dis = 2; dis <= n-1; dis++)
		{
			 for (int i = 1; i <= n; i++)
			 {
			 	  int j = next(i,dis), k = i;
			 	  for (int cnt = 1; cnt <= dis-1; cnt++)
					{
						 k = next(k,1);
						 if (f[i][k] == 1 && f[k][j] == 1 && (a[i][k]||a[j][k]))
						 {
						 	  f[i][j] = 1;
						 	  break;
						 }
					}
			 }
		}
		for (int i = 1; i <= n; i++)
		{
			 int j = i;
			 for (int cnt = 1; cnt <= n-1; cnt++)
			 {
				j = next(j,1);
				if (f[i][j] && f[j][i] && a[i][j]) {ans.push_back(i); break;}
			 }
		}
		cout << ans.size() << endl;
		for (auto k:ans) cout << k << endl;
		return 0;
}
/**Code written by AnkhoaGD**/