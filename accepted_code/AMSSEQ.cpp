#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 1e6+7;
const int INF = 1e9+7;
int n,k,res,a[N],f[N];
int main()
{
	cin >> n >> k;
	res = 0;
	fill(f+1,f+n+1,-INF);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	 for (int j = 1; (j <= k && i-j >= 0); j++)
		 f[i] = max(f[i],f[i-j]+a[i]), res = max(res,f[i]);
	cout << res;
  return 0;
}