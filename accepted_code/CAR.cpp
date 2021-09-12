//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "CAR"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1e5 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
struct mang
{
	  int X,Y,vt;
};
mang c[N];
int n;
bool cmp(mang A1,mang B1)
{
	return ((A1.X*A1.Y+(A1.Y+B1.Y)*B1.X) < (B1.X*B1.Y+(A1.Y+B1.Y)*A1.X));
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> c[i].X;
		for (int i = 1; i <= n; i++) cin >> c[i].Y;
		for (int i = 1; i <= n; i++) c[i].vt = i;
		sort(c+1,c+n+1,cmp);
		ll ans = 0,tmp = 0;
		for (int i = 1; i <= n; i++)
			ans+= (tmp+c[i].Y)*c[i].X,tmp+=c[i].Y;
		cout << ans << endl;
		for (int i = 1; i <= n; i++)
			cout << c[i].vt << " ";
		return 0;

}
/**Code written by AnkhoaGD**/


