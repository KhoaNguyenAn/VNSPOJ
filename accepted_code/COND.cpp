#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int f[N][N],res,n,fact[N];
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		fact[1] = 1;
		for (int i = 2; i <= N; i++) fact[i] = fact[i-1]*i;
		while (true)
		{
			 cin >> n;
			 if (n == -1) return 0;
			 memset(f,sizeof(f),0);
			 f[0][0] = 1;
				for (int i = 1; i <= n; i++)
				 for (int j = 1; j <= n ; j++)
						f[i][j] = f[i-1][j-1] + f[i-1][j]*j;
				res = 0;
				for (int i = 1; i <= n; i++) res += f[n][i] * fact[i];
				cout << res << endl;
		}
    return 0;
}
