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
const int mod = 1e9;

typedef pair <int,int> ii;
map <int,int> lua;
long long n,h,a[3*N],b[3*N],c[3*N],ans1,ans2,ans,dem,minPrime[3*N];

long long power(long long x,long long y)
{
		ll ans = 1;
	  ll cur = x;
	  while (y > 0)
		{
			 if (y & 1) ans = (ans*cur) % mod;
			 cur = (cur * cur) % mod;
			 y >>= 1;
		}
		return ans;
}
void ptt(int x)
{
	  while (x != 1)
		{
			  a[minPrime[x]]++;
			  x /= minPrime[x];
		}
}
void ptm(int x)
{
	  while (x != 1)
		{
			 b[minPrime[x]]++;
			 x /= minPrime[x];
		}
}
long long CATALAN(int s)
{
    for (int i = s+1; i <= 2*s; i++) ptt(i);
    for (int i = 1; i <= s+1; i++) ptm(i);
    ans1 = 1;
    ans2 = 1;
		for (int i = 2; i <= 2*s; i++)
		{
			 if (a[i] >= b[i])
			 {
					dem = a[i]-b[i];
					if (dem != 0) ans1 = (ans1*power(i,dem)) % mod;
			 }
			 else
			 {
			 	  dem = b[i]-a[i];
			 	  if (dem != 0) ans2 = (ans2*power(i,dem)) % mod;
			 }
		}
		return ((ans1/ans2) % mod);
}
int main()
{
	FastRead;
	cin >> n >> h;
	for (int i = 1; i <= n ; i++)
  {
			cin >> c[i];
  }
	minPrime[1] = 1;
  for (int i = 2; i * i <= 3*n; ++i)
	{
    if (minPrime[i] == 0)
		 {
        for (int j = i * i; j <= 3*n; j += i)
				{
            if (minPrime[j] == 0)
                minPrime[j] = i;
        }
		}
	}
	for (int i = 2; i <= 3*n; ++i)
	{
			if (minPrime[i] == 0)
        minPrime[i] = i;
	}
	ans = 2;
	for (int i = n-1; i >= 1; i--)
		if (c[i] > c[i+1]) break; else ans++;
	cout << ans << endl << CATALAN(n+1);
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}