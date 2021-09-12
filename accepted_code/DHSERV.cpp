//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "DHSERV"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 500 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long d[N][N],n,m,k,u,v,w,t,x;
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		scanf("%d %d %d",&n,&m,&k);
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
			  if (i != j) d[i][j] = INF64; else d[i][i] = 0;
		while (m--)
		{
			 scanf("%d %d %lld",&u,&v,&w);
			 d[u][v] = w;
		}
		while (k--)
		{
			 scanf("%d",&t);
			 if (t == 1)
			 {
			 	 scanf("%d",&x);
			 	 for (int i = 1; i <= n; i++)
					for (int j = 1; j <= n; j++)
					  d[i][j] = min(d[i][j],d[i][x]+d[x][j]);
			 }
			 else
			 {
				 scanf("%d %d",&u,&v);
				 if (d[u][v] != INF64) cout << d[u][v] << endl; else cout << -1 << endl;
			 }
		}
		return 0;
}
/**Code written by AnkhoaGD**/


