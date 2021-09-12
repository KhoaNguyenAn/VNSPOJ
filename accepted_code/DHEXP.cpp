#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 1e5+6;
long long n,k,a[N],ans;
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+2,a+n+1);
	ans = a[1];
	for (int i = n; i >= 2; i--)
		 if (k > 0) k--,ans+=a[i]; else ans-=a[i];
	cout << ans;
	return 0;
}