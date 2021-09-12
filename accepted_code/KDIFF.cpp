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
const int N = 3e5+10;
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
deque <int> mmax;
deque <int> mmin;
long long n,m,f[N],g[N],res,a[N];
int main()
{
	FastRead;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	 for (int j = f[i-1]; j <= i; j++)
		{
			while (!mmax.empty() && mmax.front() < j) mmax.pop_front();
			while (!mmin.empty() && mmin.front() < j) mmin.pop_front();
			while (!mmax.empty() && a[mmax.back()] < a[i]) mmax.pop_back();
			while (!mmin.empty() && a[mmin.back()] > a[i]) mmin.pop_back();
			mmax.push_back(i);
			mmin.push_back(i);
			if (abs(a[mmax.front()]-a[mmin.front()] <= m))
			{
					f[i] = j;
					break;
			}
		}
	for (int i = 1; i <= n; i++) g[i] = max(g[i-1],i-f[i]+1);
	res = 1;
	for (int i = 1; i <= n; i++)
		res = max(res,i+1-f[i]+g[f[i]-1]);
	cout << res;
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}