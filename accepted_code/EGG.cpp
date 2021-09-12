#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e9 + 7;

ll f[3000][3000],n,m,t;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		for (int i = 1; i <= 1000; i++)
		 for (int j = 1; j <= 1000; j++)
		    f[i][j] = f[i-1][j] + f[i-1][j-1]+ 1;
		cin >> t;
		while (t--)
		{
			 cin >> n >> m;
			 for (int i = 1; i <= 1000;i++)
				 if (f[i][n] >= m)
				 {
				 	  cout << i << endl;
				 	  break;
				 }
		}
		return 0;
}