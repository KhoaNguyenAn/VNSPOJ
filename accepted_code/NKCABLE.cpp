#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,a[N],f[N];
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     cin >> n;
     for (int i = 1; i < n; i++)
			 cin >> a[i];
		f[1] = a[1];
		for (int i = 2; i <= n; i++) f[i] = min(f[i-1],f[i-2]) + a[i-1];
			cout << f[n];
     return 0;
}
