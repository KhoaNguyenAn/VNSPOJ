#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
const int N = 1e6;
int n,tmp,f[N][20],res,c[20][20];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	  for (int j = 0; j < n; j++)
			cin >> c[i][j];
	for (int i = 0; i <= (1<<n)-1;i++)
	for (int j = 0; j < n ; j++) f[i][j] = INF;

	for (int i = 0; i < n ; i++) f[0][i] = 0;

	for (int i = 0; i <= (1 << n)-1; i++)
		for (int j = 0; j < n; j++)
			if ((i & (1 << j)) != 0)
			{
				tmp = (i ^ (1 << j));
				for (int k = 0; k < n; k++)
				if ((i & (1 << k)) != 0)
						f[i][j] = min(f[i][j],f[tmp][k]+c[k][j]);
			}
		res = INF;
		for (int i = 0; i < n; i++)
			res = min(res,f[(1<<n)-1][i]);
		cout << res;
    return 0;
}
