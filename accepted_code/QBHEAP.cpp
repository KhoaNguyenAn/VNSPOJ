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
const int N = 1e6+6;
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
ll tmp,k,y,a[N],b[N],sl,res;
char x;
priority_queue <ll> heap;
int main()
{
	//freopen("QBHEAP.inp","r",stdin);
	//freopen("QBHEAP.out","w",stdout);
	FastRead;
	while (cin >> x)
	{
		  if (x == '+')
			{
				 cin >> y;
				 if (heap.size() < 15000) heap.push(y);
			}
			else
			{
				if (!heap.empty())
				{
				 tmp = heap.top();
				 while (!heap.empty())
				 {
				 	  k = heap.top();
				 	  if (k == tmp) heap.pop(); else break;
				 }
				}
			}
	}
	sl = 0;
	while (!heap.empty())
	{
			a[++sl] = heap.top();
		  heap.pop();
	}
	sort(a+1,a+sl+1);
	a[sl+1] = INF;
	for (int i = sl; i >= 1; i--)
		  if (a[i] != a[i+1]) b[++res] = a[i];
	cout << res << endl;
	for (int i = 1; i <= res; i++) cout << b[i] << endl;
	return 0;
}