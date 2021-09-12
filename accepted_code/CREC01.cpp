#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
long long n,m,d[N],top,stk[N],L[N],ans,dem[N];
char a[N][N];
string st;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
		{
			 top = 0;
			 stk[top] = 0;
			 for (int j = 1; j <= m; j++)
			 if (a[i][j] == '1')
			 {
				d[j]+=1;
				while (top != 0 && d[j] <= d[stk[top]]) top--;
				L[j] = stk[top] + 1;
				stk[++top] = j;
				dem[j] = dem[L[j]-1]+d[j]*(j-L[j]+1);
				ans+=dem[j];
			 }
			 else
			 {
			 	 d[j] = 0;
			 	 dem[j] = 0;
				 L[j] = j;
				 stk[++top] = j;
			 }
		}
		cout << ans;
		return 0;
}
