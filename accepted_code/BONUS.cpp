#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 1e3 + 5;
long long n,k,f[N][N],res,x;
long long sum(int x, int y, int u ,int v)
{
	  return (f[u][v]-f[u][y-1]-f[x-1][v]+f[x-1][y-1]);
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
			{
				  cin >> f[i][j];
				  f[i][j] = f[i-1][j] + f[i][j-1] + f[i][j] - f[i-1][j-1];
			}
		res = 0;
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
		  if (i - k >= 0 && j - k >= 0) res = max(res,sum(i-k+1,j-k+1,i,j));
		cout << res;
    return 0;
}
