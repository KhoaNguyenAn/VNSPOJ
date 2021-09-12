#include <bits/stdc++.h>
#include <iostream>
#define taskname "PALINY"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 5e6 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
ll ans,d[N],hashL[N],hashR[N],power[N];
int n,mid,l,r;
string st;
queue <int> que;
inline long long check_left(int L,int R)
{
	  return (hashL[R]-(hashL[L-1]*power[R-L+1])%MOD+MOD) % MOD;
}
inline long long check_right(int L,int R)
{
	  return (hashR[L]-(hashR[R+1]*power[R-L+1])%MOD+MOD) % MOD;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n;
		cin >> st;
		power[0] = 1;
		for (int i = 1; i <= n; i++) power[i] = (power[i-1]*base) % MOD;
		st = '#' + st;
	  for (int i = 1; i <= n; i++)
			 hashL[i] = (hashL[i-1]*base + st[i] - 'a' + 1) % MOD;
		for (int i = n; i >= 1; i--)
			 hashR[i] = (hashR[i+1]*base + st[i] - 'a' + 1) % MOD;
		ans = 1;
		for (int i = 1; i <= n; i++)
		{
			 // xau palin le
			 l = 0, r = min(i-1,n-i-1);
			 while (l <= r)
			 {
					ll mid = (l+r) >> 1;
					if (check_left(i-mid,i) == check_right(i,i+mid))
					{
						ans = max(ans,mid * 2 + 1);
					  l = mid+1;
					} else r = mid-1;
			 }
			 // xau palin chan
			 l = 0, r = min(i,n-i);
       while (l <= r)
			 {
			 	  ll mid = (l+r) >> 1;
			 	  if (check_left(i-mid+1,i) == check_right(i+1,i+mid))
					{
						ans = max(ans,mid*2);
						l = mid+1;
					}
					else r = mid-1;
			 }
		}
		cout << ans;
		return 0;

}



