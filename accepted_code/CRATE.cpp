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
struct mang
{
	int x,y,z;
};
mang a[N];
ll ans[4*N],n,sum,b[N];
bool cmp(mang A1,mang B1)
{
	return ((A1.x < B1.x) || (A1.x == B1.x && A1.y < B1.y));
}
void update(int idx,int l,int r,int pos)
{
	if (l==r)
	{
		ans[idx]+=1;
		return;
	}
	int mid = (l+r) >> 1;
	if (pos > mid) update(idx*2+1,mid+1,r,pos);
	else update(idx*2,l,mid,pos);
	ans[idx] = ans[idx*2]+ans[idx*2+1];
}
int get(int idx,int l,int r,int L,int R)
{
	  if ((L<=l) && (r<=R)) return ans[idx];
	  int mid = (l+r) >> 1;
	  if (L > mid) return get(idx*2+1,mid+1,r,L,R);
	  else if (R <= mid) return get(idx*2,l,mid,L,R);
		return (get(idx*2,l,mid,L,R) + get(idx*2+1,mid+1,r,L,R));
}
int main()
{
	FastRead;
	cin >> n;
	for (int i = 1; i <= n ; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].z = i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i = 1; i <= n; i++)
	{
		if (a[i].x == a[i-1].x && a[i].y == a[i-1].y) sum = b[a[i-1].z];
					else sum = get(1,0,100000,0,a[i].y);
		update(1,0,100000,a[i].y);
		b[a[i].z] = sum;
	}
	for (int i = 1; i <= n; i++) cout << b[i] << "\n";
	return 0;
}