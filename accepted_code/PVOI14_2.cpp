///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "PVOI14_2"
#define Eureka cerr << "Eureka"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1000 + 2;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
deque <ii> que;
int dh[2] = {1,0};
int dc[2] = {0,1};
int n,a[N][N],p[N*N],cnt[N*N],res = 0;
vector <ii> V[N*N];
inline int pos(int uu,int vv)
{
	 return n*(uu-1) + vv;
}
inline int getroot(int x)
{
	 if (p[x] == 0) return x;
	 p[x] = getroot(p[x]);
	 return p[x];
}
void Union(int u,int v)
{
	 res = max(res,cnt[u]+cnt[v]);
	 if (cnt[u] >= cnt[v])
	 {
	 	   cnt[u]+=cnt[v];
	 	   p[v] = u;
	 }
	 else
	 {
	 	   cnt[v]+=cnt[u];
	 	   p[u] = v;
	 }
}
int main()
{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
		    scanf("%d",&a[i][j]);
		int high = 0;
		for (int i = 1; i <= n; i++)
		 for (int j = 1; j <= n; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					int x = i + dh[k];
			 	  int y = j + dc[k];
			 	  if (x >= 1 && x <= n && y >= 1 && y <= n)
			    {
						 int d = abs(a[i][j]-a[x][y]);
						 high = max(high,d);
						 V[d].push_back(ii(pos(i,j),pos(x,y)));
					}
				}
			}
		for (int i = 0; i <= high; i++)
		{
				for (int k = 0; k < V[i].size(); k++)
				{
					 cnt[V[i][k].X] = 1;
					 cnt[V[i][k].Y] = 1;
					 p[V[i][k].X] = 0;
					 p[V[i][k].Y] = 0;
				}
			  for (int k = 0; k < V[i].size(); k++)
				{
					  int x = getroot(V[i][k].X);
					  int y = getroot(V[i][k].Y);
					  if (x != y) Union(x,y);
				}
		}
		cout << res;
		return 0;
}
/**Code written by AnkhoaGD**/