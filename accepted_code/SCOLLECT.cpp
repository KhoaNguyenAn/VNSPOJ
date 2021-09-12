//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "SCOLLECT"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,m,dp[129][129][129],a[129][129];
int dh[]={1,0},dc[]={0,1};
char k;
int cal(int h1,int c1,int h2,int c2)
{
		if (h1 == n && c1 == m) return 0;
		if (h2 == n && c2 == m) return 0;
		int &res = dp[h1][c1][h2];
		if (res != -1) return dp[h1][c1][h2];
		res = -INF;
		for (int i = 0; i < 2; i++)
		{
			  int xx = h1+dh[i];
			  int yy = c1+dc[i];
			  if (xx <= n && yy <= m)
				{
					 for (int j = 0; j < 2; j++)
					 {
					 	  int x = h2+dh[j];
					 	  int y = c2+dc[j];
					 	  if (x <= n && y <= m)
							{
								 if (a[xx][yy]==-1 || a[x][y] == -1) continue;
								 int tmp = cal(xx,yy,x,y);
								 if (xx == x && yy == y) tmp+=a[xx][yy];
								 else tmp+=a[xx][yy]+a[x][y];
								 res = max(res,tmp);
							}
					 }
				}
		}
		//cout << h1 << " " << c1 << " " << h2 << " " << c2 << " " << res << '\n';
		return res;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> m >> n;
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= m; j++)
			{
				cin >> k;
				if (k == '*') a[i][j] = 1;
				if (k == '#') a[i][j] = -1;
				if (k == '.') a[i][j] = 0;
			}
		memset(dp,-1,sizeof dp);
		if (a[1][1] != -1)
		cout << max(cal(1,1,1,1)+a[1][1],0) << endl; else cout << 0;
		return 0;
}

