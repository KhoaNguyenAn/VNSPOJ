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
int n,m,d[N],seen[N],a[N],x;
int main()
{
	FastRead;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	fill(d,d+a[1],INF);
	d[0] = 0;
	seen[0] = 0;
	priority_queue<int,vector<int>,greater<int>> heap;
	heap.push(0);
	while (!heap.empty())
	{
		 int tmp = heap.top() % a[1];
		 heap.pop();
		 if (seen[tmp] == 1) continue;
		 seen[tmp] = 1;
		 for (int i = 1; i <= n; i++)
		 {
				x = (tmp+a[i]) % a[1];
				if (d[x] > d[tmp] + a[i])
				{
					 d[x] = d[tmp] + a[i];
					 heap.push(d[x]);
				}
		 }
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
  {
		cin >> x;
		if (x >= d[x%a[1]]) cout << "TAK \n"; else cout << "NIE \n";
  }
  return 0;
}