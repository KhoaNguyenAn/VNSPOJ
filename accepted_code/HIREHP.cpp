///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "HIREHP"
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
long long IT[4*N],F[N],t[N],p[N],n;
void build(int idx,int l,int r)
{
	 if (l == r)
	 {
	 	  IT[idx] = INF64;
	 	  return;
	 }
	 int mid = (l+r) >> 1;
	 build(idx*2,l,mid);
	 build(idx*2+1,mid+1,r);
	 IT[idx] = min(IT[idx*2],IT[idx*2+1]);
}
void update(int idx,int l, int r,int pos,long long val)
{
	  if (l == r)
		{
			  IT[idx] = min(IT[idx],val);
			  return;
		}
		int mid = (l+r) >> 1;
		if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
		else update(idx*2,l,mid,pos,val);
		IT[idx] = min(IT[idx*2],IT[idx*2+1]);
}
long long get(int idx,int l,int r,int L,int R)
{
	  if (l >= L && r <= R) return IT[idx];
	  int mid = (l+r) >> 1;
	  if (L > mid) return get(idx*2+1,mid+1,r,L,R);
	  else if (R <= mid) return get(idx*2,l,mid,L,R);
	  return min(get(idx*2+1,mid+1,r,L,R),get(idx*2,l,mid,L,R));
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
		for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
		fill(F,F+n+1,INF64);
		build(1,1,N);
		F[1] = p[1];
		update(1,1,N,t[1],F[1]);
		for (int i = 2; i <= n; i++)
		{
			 F[i] = min(F[i],get(1,1,N,i,N));
			 update(1,1,N,t[i],F[i-1]+p[i]);
			 F[i] = min(F[i],F[i-1]+p[i]);
		}
		cout << F[n];
		return 0;
}
/**Code written by AnkhoaGD**/