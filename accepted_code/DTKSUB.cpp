#include <bits/stdc++.h>
#include <iostream>
#define taskname "DTKSUB"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 5e4 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 5e7 + 13;
const ll MODLL = 1e10 + 13;
const ll base = 311;
ll n,k,hashL[N],power[N],ans,l,r;
string st;
queue <int> que;
int m[int(1e8)];
bool check(int len)
{
	int res = 1;
	for (int i = 1; i <= n-len+1; i++)
	{
		 long long tmp = (hashL[i+len-1]-(hashL[i-1]*power[len])%MOD+MOD)%MOD;
		 m[tmp]++;
		 res = max(res,m[tmp]);
	}
	if (res >= k) return true; else return false;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n >> k;
		cin >> st;
		st = '#' + st;
		power[0] = 1;
		for (int i = 1; i <= n; i++) power[i] = (power[i-1]*base) % MOD;
		for (int i = 1; i <= n; i++) hashL[i] = (hashL[i-1]*base+st[i]-'a'+1)%MOD;
		l = 0;
		r = n;
		while (l <= r)
		{
			 int mid = (l+r) >> 1;
			 if (check(mid)==true)
			 {
			 	   ans = mid;
			 	   l = mid+1;
			 }
			 else r = mid-1;
		}
		cout << ans;
		return 0;

}



