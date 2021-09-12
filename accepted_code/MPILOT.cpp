//Kaze
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <iostream>
#define taskname "MPILOT"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,x[10001],y[10001],f[10001][10001];
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> x[i] >> y[i];
		f[1][1] = y[1];
		for (int i = 2; i <= n; i++)
		{
			  f[i][0] = f[i-1][1]+x[i];
			  f[i][i] = f[i-1][i-1]+y[i];
			  for (int j = 1; j <= i-1; j++)
					f[i][j] = min(f[i-1][j-1]+y[i],f[i-1][j+1]+x[i]);
		}
		cout << f[n][0];
		return 0;

}
/**Code written by AnkhoaGD**/


