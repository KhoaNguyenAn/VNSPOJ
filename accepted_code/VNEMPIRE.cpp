///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "VNEMPIRE"
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
const ll N = 5e5 + 7;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
struct data
{
	  long long x,y,z,id;
};
data a[N],S[N];
long long n,m,x,y,z,p[N],res = 0;
int getroot(int x)
{
	if (p[x] == 0) return x;
	p[x] = getroot(p[x]);
	return p[x];
}
long long dis(data A1,data B1)
{
	return min(min(abs(A1.x-B1.x),abs(A1.y-B1.y)),abs(A1.z-B1.z));
}
bool cmp1(data A1,data B1)
{
	 return A1.x < B1.x;
}
bool cmp2(data A1,data B1)
{
	 return A1.y < B1.y;
}
bool cmp3(data A1,data B1)
{
	 return A1.z < B1.z;
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
			  cin >> x >> y >> z;
			  a[i] = {x,y,z,i};
		}
		m = 0;
		sort(a+1,a+n+1,cmp1);
		for (int i = 1; i <= n-1; i++)
			S[++m] = {dis(a[i],a[i+1]),a[i].id,a[i+1].id};
		sort(a+1,a+n+1,cmp2);
		for (int i = 1; i <= n-1; i++)
			S[++m] = {dis(a[i],a[i+1]),a[i].id,a[i+1].id};
		sort(a+1,a+n+1,cmp3);
		for (int i = 1; i <= n-1; i++)
			S[++m] = {dis(a[i],a[i+1]),a[i].id,a[i+1].id};
		sort(S+1,S+m+1,cmp1);
		for (int i = 1; i <= m; i++)
		{
			 int x = getroot(S[i].y);
			 int y = getroot(S[i].z);
			 if (x != y)
			 {
			 	  p[x] = y;
			 	  res+=S[i].x;
			 }
		}
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/