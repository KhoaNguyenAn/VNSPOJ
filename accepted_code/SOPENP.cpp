#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+1;
const int INF = 1e9+7;
typedef long long ll;
ll n,l,u,a[N],j,dem,ans;
unordered_map <int,int> s;
ll cal(ll k)
{
	  ll j = 0,dem = 0,res = 0;
	  for (int i = 1; i <= n; i++)
		{
			 while (dem <= (k-1) && j <= n)
			 {
			 	  j++;
			 	  if (s[a[j]] == 0) dem++;
			 	  s[a[j]]++;
			 }
			 res+=j-1;
       s[a[i]]--;
       if (s[a[i]] == 0) dem--;
		}
		return res;
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> l >> u;
    for (int i = 1; i <= n; i++) cin >> a[i];
		cout << cal(u+1)-cal(l);
		return 0;
}
