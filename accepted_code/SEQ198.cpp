#include <bits/stdc++.h>
#include <iostream>
#define taskname "SEQ198"
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
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
const long long base189 = (1 << 1) + (1 << 8) + (1 << 9);
ll n,m,ans,a[3000],f[3000][3000],dis,k;
queue <int> que;
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		memset(f,-1,sizeof f);
		for (int i = 1; i <= n; i++)
		{
			f[i][0] = 0;
			f[i][1] = 1;
		}
		for (int i = 2; i <= n; i++)
		{
				dis = a[i]-a[i-1];
				for (int j = 0; j < 1024; j++)
		    if (f[i-1][j] >= 0)
		    {
					 if (dis >= 10) k = 0; else k = ((j << dis) & 1023);
					 f[i][k] = max(f[i-1][j],f[i][k]);
					 if ((k & base189) == 0)
						f[i][k | 1] = max(f[i][k | 1],f[i-1][j] + 1);
				}
		}
		ans = -1;
		for (int i = 0; i < 1024; i++) ans = max(ans,f[n][i]);
		cout << n-ans;
		return 0;

}



