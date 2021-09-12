#include <bits/stdc++.h>
#include <iostream>
#define taskname "NKJUMP"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e3 + 5;
const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
deque <int> res;
queue <int> que;
vector <int> a[N];
int b[N],ans,n,seen[N],f[N];
unordered_map <int,int> m;
void DFS(int u)
{
	  seen[u] = 1;
	  for (int k = 0; k < a[u].size(); k++)
		{
			 int v = a[u][k];
			 if (seen[v] == 0) DFS(v);
		}
		res.push_front(u);
		seen[u] = 2;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("taskname".INP","r",stdin);
		//freopen("taskname".OUT","w",stdout);
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> b[i];
			m[b[i]] = i;
		}
		for (int i = 1; i < n; i++)
		 for (int j = i+1; j <= n; j++)
				{
					int k = m[b[i]+b[j]];
					if (k != 0)
					{
						 a[i].push_back(k);
						 a[j].push_back(k);
					}
				}
	  memset(seen,0,sizeof seen);
	  for (int i = 1; i <= n; i++)
		if (seen[i] == 0) DFS(i);
		for (int i = 0; i < res.size(); i++)
		{
			int u = res[i];
		  for (int j = 0; j < a[u].size(); j++)
			{
				int v = a[u][j];
				f[v] = max(f[v],f[u]+1);
			}
		}
		ans = -INF;
	 for (int i = 0; i < res.size(); i++) ans = max(ans,f[i]);
		cout << ans+1;
	 return 0;
}



