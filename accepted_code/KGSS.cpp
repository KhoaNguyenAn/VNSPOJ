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
struct data
{
	 int index;
	 ll value;
};
data IT[4*N];
ll n,a[N],m;
int u,v;
char x;
data cmp(data A1,data B1)
{
	 if (A1.value >= B1.value) return A1;else return B1;
}
void build(int idx,int l,int r)
{
	if (l == r)
	{
		 IT[idx] = {l,a[l]};
		 return;
	}
	int mid = (l+r) >> 1;
	build(idx*2,l,mid);
	build(idx*2+1,mid+1,r);
	IT[idx] = cmp(IT[idx*2],IT[idx*2+1]);
}
void update(int idx,int l,int r,int pos,ll val)
{
  if (l == r)
	{
		 IT[idx] = {pos,val};
		 return;
	}
	int mid = (l+r) >> 1;
	if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
	else update(idx*2,l,mid,pos,val);
	IT[idx] = cmp(IT[idx*2],IT[idx*2+1]);
}
data get(int idx,int l,int r,int L,int R)
{
	if (L <= l && r <= R) return IT[idx];
	int mid = (l+r) >> 1;
	if (L > mid) return get(idx*2+1,mid+1,r,L,R);
	else
	if (R <= mid) return get(idx*2,l,mid,L,R);
	return cmp(get(idx*2,l,mid,L,R),get(idx*2+1,mid+1,r,L,R));
}
int main()
{
	FastRead;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1,1,n);
	cin >> m;
	while (m--)
	{
		cin >> x >> u >> v;
		if (x == 'U') update(1,1,n,u,v);
		else
		{
			data p,pl,pr;
			p = get(1,1,n,u,v);
			if (p.index != u) pl = get(1,1,n,u,p.index-1); else pl.value = -INF;
			if (p.index != v) pr = get(1,1,n,p.index+1,v); else pr.value = -INF;
			cout << p.value + max(pl.value,pr.value) << endl;
		}
	}
 return 0;
}