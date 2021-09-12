#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long s,q,m,n;
bool check(long long s1, long long s2)
{
		long long xx = s1 & s2;
		long long yy = (~s1 & ~s2) & (s-1);
		return !(xx & (xx>>1)) && !(yy & (yy>>1));
}
long long solve(int n1,int m1)
{
		s = 1<<m1;
		long long f[n1][s];
		for (int i = 0; i < s; i++) f[0][i] = 1;
		for (int i = 1; i < n1; i++)
		for (int j = 0; j < s; j++)
		{
				f[i][j] = 0;
				for (int k = 0; k < s; k++)
				if (check(j,k)) f[i][j]+=f[i-1][k];
		}
		long long res = 0;
		for (int i = 0; i < s; i++) res+=f[n1-1][i];
		return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> q;
	while (q--)
	{
		 cin >> n >> m;
		 cout << solve(max(n,m),min(n,m)) << endl;
	}
	return 0;
}