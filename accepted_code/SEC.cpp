#include <bits/stdc++.h>
#include <iostream>
#define taskname "SEC"
#define X first
#define Y second
#define MOD 1000000007ll
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 2e6 + 5;
const ll INF = 1e9 + 10;
ll n,m,ans,d[N],sl,x;
string st;
queue <int> que;
struct Trie_node
{
	  int child[2],cnt_end,cnt_cross;
};
vector <Trie_node> Trie;
Trie_node Add_node()
{
		Trie_node res;
		for (int k = 0; k <= 1; k++)
		{
			 res.child[k] = -1;
			 res.cnt_cross = 0;
		}
		res.cnt_end = 0;
		return res;
}
void Add(const string &s)
{
	 int root = 0;
	 for (int ii = 0; ii < s.size(); ii++)
	 {
			int nxt = s[ii] - '0';
	 	  if (Trie[root].child[nxt] == -1)
			{
				 Trie.push_back(Add_node());
				 Trie[root].child[nxt] = Trie.size()-1;
			}
			root = Trie[root].child[nxt];
			Trie[root].cnt_cross++;
	 }
	 Trie[root].cnt_end++;
}
inline long long check(const string &s)
{
	 int root = 0;
	 long long ans = 0;
	 bool ok = true;
	 for (int ii = 0; ii < s.size(); ii++)
	 {
	 	  int nxt = s[ii] - '0';
	 	  if (Trie[root].child[nxt] == -1)
			{
				 ok = false;
				 break;
			}
			root = Trie[root].child[nxt];
			ans+= Trie[root].cnt_end;
	 }
	 if (ok == true) ans+= Trie[root].cnt_cross - Trie[root].cnt_end;
	 return ans;
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		//freopen("SEC.INP","r",stdin);
		//freopen("SEC.OUT","w",stdout);
		cin >> m >> n;
		Trie.push_back(Add_node());
		for (int i = 1; i <= m; i++)
		{
			 cin >> sl;
			 string st = "";
			 for (int j = 1; j <= sl; j++)
			 {
			 	   cin >> x;
			 	   st = st + char(x+'0');
			 }
			 Add(st);
		}
		for (int i = 1; i <= n; i++)
		{
			 cin >> sl;
			 string st = "";
			 for (int j = 1; j <= sl; j++)
			 {
			 	  cin >> x;
			 	  st = st + char(x+'0');
			 }
			 cout << check(st) << endl;
		}
		return 0;
}



