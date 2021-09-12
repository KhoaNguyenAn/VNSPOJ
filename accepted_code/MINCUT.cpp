#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
const int N = 1e3+5;
long long n,m,k,a[N][N],f[N][N],xx,yy,x2,y2,mid,s,full,half,res,l,r;
long long sum(int x ,int y,int u,int v)
{
	  return (f[u][v] - f[x-1][v] - f[u][y-1] + f[x-1][y-1]);
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				f[i][j] = f[i-1][j] + f[i][j-1] + a[i][j] - f[i-1][j-1];
			}
		while (k--)
		{
			 cin >> xx >> yy >> x2 >> y2;
			 full = sum(xx,yy,x2,y2);
			 half = full >> 1;
			 res = 1ll << 60;
			 l = xx; r = x2;
			 while (l <= r)
			 {
					 mid = (l+r) >> 1;
					 s = sum(xx,yy,mid,y2);
					 if (s < half) l = mid+1; else r = mid-1;
			 }
			 res = min(res,min(abs(full-2*sum(xx,yy,l,y2)),abs(full-2*sum(xx,yy,r,y2))));
			 l = yy; r = y2;
			 while (l <= r)
			 {
			 	   mid = (l+r) >> 1;
					 s = sum(xx,yy,x2,mid);
			 	   if (s < half) l = mid+1; else r = mid-1;
			 }
			 res = min(res,min(abs(full-2*sum(xx,yy,x2,l)),abs(full-2*sum(xx,yy,x2,r))));
			 cout << res << "\n";
		}
    return 0;
}
