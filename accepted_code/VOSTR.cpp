#include <bits/stdc++.h>
#include <iostream>
#define taskname "VOSTR_VOI2013"
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
queue <int> que;
long long hash1[N],hash2[N],n1,n2,l,r,u,v,q,ans,power[N];
string st1,st2;
bool check(int x)
{
	 long long tmp1 = (hash1[l+x-1]-(hash1[l-1]*power[x])%MOD+MOD) %MOD;
	 long long tmp2 = (hash2[u+x-1]-(hash2[u-1]*power[x])%MOD+MOD) %MOD;
	 if (tmp1 != tmp2) return false; else return true;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n1 >> n2;
		power[0] = 1;
		for (int i = 1;i <= max(n1,n2); i++)
		   power[i] = (power[i-1]*base) % MOD;
		cin >> st1;
		cin >> st2;
		st1 = '#' + st1;
		st2 = '#' + st2;
		for (int i = 1; i <= n1; i++) hash1[i] = (hash1[i-1]*base+st1[i]-'a'+1) %MOD;
		for (int i = 1; i <= n2; i++) hash2[i] = (hash2[i-1]*base+st2[i]-'a'+1) %MOD;
		cin >> q;
		while (q--)
		{
       cin >> l >> r >> u >> v;
			 int L = 0, R = min(r-l+1,v-u+1);
			 while (L <= R)
			 {
			 	  int mid = (L+R)>>1;
			 	  if (check(mid) == true)
					{
             L = mid+1;
             ans = mid;
					}
					else R = mid-1;
			 }
       if (min(r-l+1,v-u+1) == ans)
			 {
			 	  if (r-l+1 == v-u+1) cout << "=";
			 	  else
					if (r-l+1 < v-u+1) cout << "<"; else cout << ">";
			 }
			 else
			 if (st1[l+ans]< st2[u+ans]) cout << "<"; else cout << ">";
		}

		return 0;

}



