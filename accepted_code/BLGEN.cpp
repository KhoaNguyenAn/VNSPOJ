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
map <int,int> lua;
string st,st1;
ull sl1,sl2,a[N],b[N],f[3000][3000],k;
bool snt(ull p)
{
	if (p == 0) return false;
	for (int i = 2; i*i <= p; i++)
		if (p % i == 0) return false;
	return true;
}
bool check(ull x)
{
	 ull tmp = round(pow(x,0.5));
	 if (tmp*tmp == x) return true;
	 tmp = round(pow(x,(1.0/3.0)));
	 if (tmp*tmp*tmp == x && snt(tmp)==true) return true;
	 return false;
}
int main()
{
	//freopen("BLGEN.inp","r",stdin);
//	freopen("BLGEN.out","w",stdout);
	FastRead;
	getline(cin,st);
	stringstream s(st);
	while (s>>k) if (check(k)==true) a[++sl1] = k;
	getline(cin,st1);
	stringstream s1(st1);
	while (s1>>k) if (check(k)==true) b[++sl2] = k;
	for (int i = 1; i <= sl1; i++)
	 for (int j = 1; j <= sl2; j++)
			if (a[i] == b[j]) f[i][j] = max(f[i][j],f[i-1][j-1]+1); else f[i][j] = max(f[i-1][j],f[i][j-1]);
	cout << f[sl1][sl2];
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}