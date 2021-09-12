#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long s[N],p[N],a,x,y,n,xx,yy;
long long getroot(long long x1)
{
	 if (p[x1]==0) return x1;
	 p[x1] = getroot(p[x1]);
	 return p[x1];
}
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		fill(s+1,s+N+1,1);
		fill(p+1,p+N+1,0);
		for (int i = 1; i <= n; i++)
		{
			 cin >> x >> y >> a;
			 if (a==1)
			 {
					xx = getroot(x);
					yy = getroot(y);
					if (xx != yy)
			 	  {
			 	  	if (s[xx] >= s[yy])
						{
						  p[yy] = xx;
						  s[xx]+=s[yy];
						}
						else
						{
							p[xx] = yy;
							s[yy] += s[xx];
						}
			 	  }
			 }
			 else
			 {
					 xx = getroot(x);
			 	   yy = getroot(y);
			 	   if (xx!=yy) cout << "0" << endl; else cout << "1" << endl;
			 }
		}
    return 0;
}
