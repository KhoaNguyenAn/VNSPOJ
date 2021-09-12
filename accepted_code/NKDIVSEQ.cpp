#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,res=1,vt=1;
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		cin >> n;
		if (n == 1)
		{
			 cout << 1;
			 return 0;
		}
		for (int i = 2; i <= n; i++)
		{
			  vt++;
			  res = (res/i+1)*i;
			  if (vt == n) {cout << res; return 0;}
			  for (int j = 1; j <= i-1; j++)
				{
					 res = res + i;
					 vt++;
					 if (vt==n) {cout << res; return 0;}
				}
		}
    return 0;
}
