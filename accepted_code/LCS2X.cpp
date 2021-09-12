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
const int N = 1500 + 1;
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
int n,m,t,a[N],b[N],d[N],res,tmp,f[N][N];
int main()
{
	FastRead;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i];
		memset(d,0,sizeof d); // reset mang
		res = 0; // reset dap an
		// goi f[i][j] la do dai day con chung lon nhat thoa yeu cau de bai khi dung a[i] va b[j]
		// goi d[j] la max cua moi i trong f[i][j] khi duyet toi j cua mang B
		//  VI LUON DUYET I TU BE DEN LON NEN LUON DAM BAO VIEC CAP NHAT TU D[J] LUON HOP LE VOI MOI I,J
		for (int i = 1; i <= n; i++)
		{
			 tmp = 0; // gia tri duoi tot nhat co the gan vao
			 for (int j = 1; j <= m; j++)
			 {
				  if (a[i]==b[j]) // them a[i] vao cuoi cua gia tri duoi tot nhat vi a[i] = b[i] ( suy ra hop le )
						  f[i][j] = tmp+1; // cap nhat f[i][j]
					if (2*b[j] <= a[i]) tmp = max(tmp,d[j]); // cap nhap cai gia tri duoi khi
													//xet tai a[i] voi nhung thang d[j] ma tai do 2*b[j] <= a[i]
					if (a[i]==b[j])
					{
							d[j] = max(d[j],f[i][j]); // cap nhat d[j]
						  res = max(res,f[i][j]); // cap nhat nhanh dap an
					}
			 }
		}
		cout << res << endl;
	}
	#ifdef HOME
    cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
	#endif
    return 0;
}