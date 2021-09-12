///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "KVIP"
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
const ll N = 2000 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long n,a[N][N],S,F[N],res;
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
			for (int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
				if (i == j) S+=a[i][i];
			}
		}
		fill(F, F + n + 1, -INF64);
		F[1] = S;
		res = S;
    for (int i = 2; i <= n; i++)
		{
		 for (int j = 1; j < i; j++)
		 {
				F[i] = max(F[i],F[j]-a[j][1]+a[j][i]-a[i][i]+a[i][1]);
				res = max(res,F[i]);
		 }
		}
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/