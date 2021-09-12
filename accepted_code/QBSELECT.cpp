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

const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
/*....................................Functions.............................................*/
#define       sqr(x)               x*x
#define       min3(a,b,c)          min(a,min(b,c))
#define       max3(a,b,c)          max(a,max(b,c))
#define       all(v)               v.begin(), v.end()
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
const int d[8] = {0 , 1 , 2 , 4 , 5 , 8 , 9 , 10};
const int MIN = -3e5*10000;
const int N = 1e4 + 6;
long long n,ok,res,a[10][N],check[10][10],tmp,f[10][N];
bool getbit(int s,int vt)
{
	vt--;
	return (s & (1 << vt));
}
bool kt(int s1, int s2)
{
  if ((s1 & s2) == 0) return 1; else return 0;
}
long long sum(int c,int t)
{
	long long ans = 0;
	for (int ii = 1; ii <= 4; ii++) ans+= getbit(t,ii)*a[ii][c];
	return ans;
}
int main()
{
	FastRead;
	cin >> n;
	ok = MIN; res = MIN;
	for (int i = 1; i <= 4; i++)
	 for (int j = 1; j <= n; j++) {cin >> a[i][j]; ok = max(ok,a[i][j]);}
	if (ok < 0) {cout << ok; return 0;}
	for (int i = 0; i < 8; i++)
			for (int k = 0; k < 8; k++)
				check[i][k] = kt(d[i],d[k]);
	for (int i = 0; i < 8; i++) f[i][1] = sum(1,d[i]);
	for (int j = 2; j <= n; j++)
	{
	  for (int i = 0 ; i < 8; i++)
		{
			tmp = MIN;
			for (int k = 0 ; k < 8; k++)
			  if (check[i][k] == true) tmp = max(tmp,f[k][j-1]);
			f[i][j] = tmp + sum(j,d[i]);
		}
	}
	for (int i = 0; i < 8; i++) res = max(res,f[i][n]);
	cout << res;
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}