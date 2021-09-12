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
const int N = 1e5+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       all(v)               v.begin(), v.end()
//#define       ok                   cout << "ok" << endl
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
deque <ii> que[N];
long long n,m,a[N],b[N],c[N],tmp,f[300][30000];
int main()
{
	FastRead;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) f[i][j] = -INF;
	//f[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			{
				  if (a[i] > j) //khoi luong 1 vat lon hon capacity cua tui hien tai
					{
						 f[i][j] = f[i-1][j];
						 que[j].clear();
						 que[j].push_back(ii(f[i-1][j],j));
						 continue;
					}
				  tmp = j%a[i];
				  while (!que[tmp].empty())
					{
						 ii ok = que[tmp].back();
						 if (((j-ok.Y)/a[i])*b[i]+ok.X <= f[i-1][j])
							 que[tmp].pop_back(); else break;
					}
					while (!que[tmp].empty())
					{
						 ii ok = que[tmp].front();
						 if ((j-ok.Y) / a[i] > c[i]) que[tmp].pop_front(); else break;
					}
					que[tmp].push_back(ii(f[i-1][j],j));
					f[i][j] = que[tmp].front().X + (j-que[tmp].front().Y)/a[i]*b[i];
			}
	}
	long long ans=0;
	for(int i=0;i<=m;++i)ans=max(ans,f[n][i]);
	cout << ans;
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}