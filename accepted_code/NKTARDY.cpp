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
typedef pair <int,ii> iii;
map <int,int> lua;
struct mang
{
	 int p,d,c;
};
mang a[N];
bool cmp(mang A1,mang B1)
{
	 return A1.d < B1.d;
}
priority_queue <iii> heap;
ll n,b[N],c[N],tmp,tt,xx;
int main()
{
	FastRead;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].p,a[i].c = i;
	for (int i = 1; i <= n; i++) cin >> a[i].d;
	sort(a+1,a+n+1,cmp);
	tmp = 0;
	tt = 0;
	xx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (tmp+a[i].p <= a[i].d)
		{
			tmp+=a[i].p;
			b[++tt] = a[i].c;
			heap.push(iii(a[i].p,ii(a[i].c,tt)));
		}
		else
		if (!heap.empty())
		{
			iii tam = heap.top();
			if (tam.X > a[i].p)
			{
				 tmp = tmp-tam.X+a[i].p;
				 b[tam.Y.Y] = a[i].c;
				 c[++xx] = tam.Y.X;
				 heap.pop();
				 heap.push(iii(a[i].p,ii(a[i].c,tam.Y.Y)));
			}
			else c[++xx] = a[i].c;
		}
		else c[++xx] = a[i].c;
	}
	cout << xx << endl;
	for (int i = 1; i <= tt; i++) cout << b[i] << " ";
	for (int i = 1; i <= xx; i++) cout << c[i] << " ";
  return 0;
}