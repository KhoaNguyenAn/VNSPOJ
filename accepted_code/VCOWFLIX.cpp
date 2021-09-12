#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
int n,m,a[N],f[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
			cin >> a[i];
		fill(f,f+m+1,0);
		f[0] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = m; j >= a[i]; j--)
					f[j] = f[j] | (f[j-a[i]]);
		for (int i = m; i >= 0; i--)
			if (f[i])
			{
				 cout << i;
				 return 0;
			}
}
