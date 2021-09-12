#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int n,m,p[N],s[N];
struct mang
{
	 int x,y;
}; mang a[N];
int getroot(int x)
{
	 if (p[x]==0) return x;
	 p[x] = getroot(p[x]);
	 return p[x];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
			  cin >> a[i].x >> a[i].y;
		cout << 3 << endl;
		fill(s+1,s+n+1,1);
		fill(p+1,p+n+1,0);
		for (int i = 1; i <= m; i++)
		{
			int xx = getroot(a[i].x);
			int yy = getroot(a[i].y);
			if (xx != yy)
			{
				 if (s[xx] <= s[yy])
				 {
				 	  p[xx] = yy;
				 	  s[yy]+=s[xx];
				 }
				 else
				 {
				 	  p[yy] = xx;
				 	  s[xx]+=s[yy];
				 }
				 cout << a[i].x << " "<< a[i].y << endl;
			}
		}
		fill(s+1,s+n+1,1);
		fill(p+1,p+n+1,0);
		for (int i = m; i >= 1; i--)
		{
			int xx = getroot(a[i].x);
			int yy = getroot(a[i].y);
			if (xx != yy)
			{
				 if (s[xx] <= s[yy])
				 {
				 	  p[xx] = yy;
				 	  s[yy]+=s[xx];
				 }
				 else
				 {
				 	  p[yy] = xx;
				 	  s[xx]+=s[yy];
				 }
				 cout << a[i].x << " "<< a[i].y << endl;
			}
		}
		fill(s+1,s+n+1,1);
		fill(p+1,p+n+1,0);
		for (int i = 1; i <=m/3; i++)
		{
			int xx = getroot(a[i].x);
			int yy = getroot(a[i].y);
			if (xx != yy)
			{
				 if (s[xx] <= s[yy])
				 {
				 	  p[xx] = yy;
				 	  s[yy]+=s[xx];
				 }
				 else
				 {
				 	  p[yy] = xx;
				 	  s[xx]+=s[yy];
				 }
				 cout << a[i].x << " "<< a[i].y << endl;
			}
		}
		for (int i = 2*m/3+1; i <=m; i++)
		{
			int xx = getroot(a[i].x);
			int yy = getroot(a[i].y);
			if (xx != yy)
			{
				 if (s[xx] <= s[yy])
				 {
				 	  p[xx] = yy;
				 	  s[yy]+=s[xx];
				 }
				 else
				 {
				 	  p[yy] = xx;
				 	  s[xx]+=s[yy];
				 }
				 cout << a[i].x << " "<< a[i].y << endl;
			}
		}
		for (int i = m/3+1; i <=2*m/3; i++)
		{
			int xx = getroot(a[i].x);
			int yy = getroot(a[i].y);
			if (xx != yy)
			{
				 if (s[xx] <= s[yy])
				 {
				 	  p[xx] = yy;
				 	  s[yy]+=s[xx];
				 }
				 else
				 {
				 	  p[yy] = xx;
				 	  s[xx]+=s[yy];
				 }
				 cout << a[i].x << " "<< a[i].y << endl;
			}
		}
    return 0;
}
