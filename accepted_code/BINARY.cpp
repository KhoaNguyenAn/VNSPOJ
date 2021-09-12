//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "BINARY"
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
long long f[50][50][2][2],n,k;
long long cal(int bit,int cnt,int isLess,int isStart)
{
	  if (cnt > k) return 0;
	  if (bit == -1) return (cnt == k);
	  long long &res = f[bit][cnt][isLess][isStart];
	  if (res != -1) return res;
	  int x = (n >> bit) & 1;
	  // try to add bit '0'
	  if (isStart == 0)
		 res = cal(bit-1,cnt+1,isLess || x,isStart);
			else res = cal(bit-1,cnt,isLess || x,isStart);
		// try to add bit '1'
		if (isLess == 1)
		  res+= cal(bit-1,cnt,1,0);
		else if (x == 1) res+= cal(bit-1,cnt,0,0);
		return res;
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		while (cin >> n >> k)
		{
			 memset(f,-1,sizeof f);
			 if (k >= 31)
			 {
			 	  cout << 0 << endl;
			 	  continue;
			 }
			 cout << cal(31,0,0,1) + (k == 1) - (k == 0) << endl;
		}
		return 0;
}
/**Code written by AnkhoaGD**/


