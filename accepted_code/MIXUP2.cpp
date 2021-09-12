///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "MIXUP2"
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
const ll N = 1e6 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long f[N][20],ans,n,k,K,a[20];
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 ///freopen(taskname".INP","r",stdin);
		 ///freopen(taskname".OUT","w",stdout);
		#endif // Kaze
    cin >> n >> K;
    for (int i = 0; i < n; i++) cin >> a[i];
    int n1 = (1 << n) - 1;
    for (int i = 0 ; i < n; i++)
			f[(1 << i)][i] = 1;
    for (int i = 0; i <= n1; i++)
		 for (int j = 0; j < n; j++)
		 if ((i & (1 << j)))
			{
				for (int k = 0 ; k < n; k++)
				if ((i & (1 << k)) == 0 && abs(a[k]-a[j]) > K)
				  f[i | (1 << k)][k]+= f[i][j];
			}
		ans = 0;
		for (int i = 0; i < n; i++) ans+= f[n1][i];
		cout << ans;
		return 0;
}
/**Code written by AnkhoaGD**/