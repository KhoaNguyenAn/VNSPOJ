//Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "NAME"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
int n,BIT_1[N],BIT_2[N],v,L[N],R[N],cnt = 0;
long long ans,c;
vector <int> a[N];
void DFS(int u,int p)
{
	 L[u] = ++cnt;
	 for (auto v: a[u])
		  DFS(v,u);
	 R[u] = ++cnt;
}
struct mang
{
	 int idx,cost;
};
mang b[N];
bool cmp(mang A1,mang B1)
{
	 return A1.cost < B1.cost;
}
void update(int x,int val)
{
	  BIT_2[x]++;
	  for (int k = x; k <= 2*n+1; k+=(k&-k))
			BIT_1[k]++;
}
inline int get(int L,int R)
{
	  int sum = 0;
	  while (R >= L)
		{
			  if (R - (R&-R) >= L)
				{
				   sum+= BIT_1[R];
				   R = R - (R&-R);
				}
				else
				{
					 sum+= BIT_2[R];
					 R--;
				}
		}
		return sum;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen(taskname".INP","r",stdin);
		//freopen(taskname".OUT","w",stdout);
		cin >> n;
		cin >> b[1].cost;
		b[1].idx = 1;
		for (int i = 2; i <= n; i++)
		{
			 cin >> v >> c;
			 a[v].push_back(i);
			 b[i].idx = i;
			 b[i].cost = c;
		}
		DFS(1,0);
		sort(b+1,b+n+1,cmp);
		for (int i = 1,j = 1;  i <= n; i++)
		{
			 while (b[j].cost < b[i].cost)
			 {
			 	  update(L[b[j].idx],1);
			 	  j++;
			 }
			 c = get(L[b[i].idx],R[b[i].idx]);
			 ans+= c*(c-1)/2;
		}
		cout << ans;
		return 0;
}
/**Code written by AnkhoaGD**/


