///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "BEADSNB_VNSPOJ"
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
int n,f1[N],f2[N],g1[N],g2[N],ans1 = 0,ans2 = 0,ans,a[N],b[N];
int cnp1(int L,int R,int v)
{
	  while (L <= R)
		{
			 int mid = (L+R) >> 1;
			 if (g1[mid] < v) L = mid+1; else R = mid-1;
		}
		return R;
}
int cnp2(int L,int R,int v)
{
	  while (L <= R)
		{
			 int mid = (L+R) >> 1;
			 if (g2[mid] > v) L = mid+1; else R = mid-1;
		}
		return R;
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
		{
			cin >> a[i];
			b[i] = a[i];
		}
		reverse(b+1,b+n+1);
		g1[0] = INF;
		f1[0] = 0;
		ans1 = 0;
		for (int i = 1; i <= n; i++)
		{
			 int j = cnp1(1,ans1,b[i]);
			 f1[i] = j + 1;
			 g1[f1[i]] = b[i];
			 ans1 = max(ans1,f1[i]);
		}
		g2[0] = -INF;
		f2[0] = 0;
		ans2 = 0;
		for (int i = 1; i <= n; i++)
		{
			 int j = cnp2(1,ans2,b[i]);
			 f2[i] = j + 1;
			 g2[f2[i]] = b[i];
			 ans2 = max(ans2,f2[i]);
		}
		ans = 0;
		for (int i = 1; i <= n; i++) ans = max(ans,f1[i]+f2[i]-1);
		cout << ans;
		return 0;
}
/**Code written by AnkhoaGD**/