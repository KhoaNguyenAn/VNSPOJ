///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "VOSMAXK"
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
long long n,k,a[N],res = 0,L[N],R[N];
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		#ifndef Kaze
		 ///freopen(taskname".INP","r",stdin);
		 ///freopen(taskname".OUT","w",stdout);
		#endif // Kaze
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		deque <int> Q;
		for (int i = 1; i <= n; i++)
		{
			 while (!Q.empty() && a[Q.back()] < a[i])
			 {
			 	  R[Q.back()] = i-1;
			 	  Q.pop_back();
			 }
			 if (Q.empty()) L[i] = 1; else L[i] = Q.back()+1;
			 Q.push_back(i);
		}
		while (!Q.empty())
		{
			  R[Q.back()] = n;
			  Q.pop_back();
		}
		for (int i = 1; i <= n; i++)
		if (a[i] == k) res+=(i-L[i]+1)*(R[i]-i+1);
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/