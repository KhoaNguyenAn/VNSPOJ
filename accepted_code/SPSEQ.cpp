///...................................*****.................................................///
///        Author :  Ankhoa                                                                 ///
///                  Department of Computer Science                                         ///
///                  & Algorithm                                                            ///
///                  Gia Dinh high school , Vietnam.                                        ///
///...................................*****.................................................///
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
#include <sstream>
#include <set>
#include <list>
#include <map>
#include <stack>
using namespace std;
/*....................................Values................................................*/
#define       PI                   acos(-1)
#define       M                    1000000007
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define base 27ll
#define MAXN 1000010
#define MOD 1000000007ll
const int N = 3e5+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       all(v)               v.begin(), v.end()
#define       ok                   cout << "ok" << endl
#define       mem(x,y)             memset(x,y,sizeof(x))
#define       READ(f)              freopen(f, "r", stdin)
#define       WRITE(f)             freopen(f, "w", stdout)
/*.....................................Loops...............................................*/
#define       rep( i , a , b )     for( i=a ; i<b ; i++)
#define       rev( i , a , b )     for( i=a ; i>=b ; i--)
#define       repx( i ,a,b, x)     for( i=a ; i<b ; i+=x)

#define       FastRead             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
/*..................................Shutdown..............................................*/


typedef pair <int,int> ii;
map <int,int> lua;
int n,ans1,ans2,res,g[N],f[N],s[N],a[N],j;
int bns(int l,int r,int v)
{
		while (l <= r)
		{
			int mid = (l+r) >> 1;
			if (g[mid] >= v) r = mid-1;else l = mid+1;
		}
		return r;
}
int main()
{
	FastRead;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ans1 = 0;
	ans2 = 0;
	g[0] = INF;
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		 j = bns(1,ans1,a[i]);
		 f[i] = j+1;
		 g[f[i]] = a[i];
		 ans1 = max(ans1,f[i]);
	}
  memset(g,0,sizeof g);
  for (int i = n; i >= 1; i--)
	{
		 j = bns(1,ans2,a[i]);
		 s[i] = j+1;
		 g[s[i]] = a[i];
		 ans2 = max(ans2,s[i]);
	}
	for (int i = 1; i <= n; i++)
		 res = max(res,min(f[i],s[i])*2-1);
	cout << res;
  return 0;
}