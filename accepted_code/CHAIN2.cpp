#include <bits/stdc++.h>
#include <iostream>
#define taskname "NAME"
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
int n,m,ans;
string st;
queue <int> que;
struct Trie_node
{
	 int child[26];
	 bool is_End;
};
vector <Trie_node> Trie;
Trie_node Add_node()
{
	 Trie_node res;
	 for (int i = 0; i < 26; i++)
		 res.child[i] = -1;
	 res.is_End = false;
	 return res;
}
void Add(const string &s)
{
	 int root = 0;
	 for (int i = 0; i < s.size(); i++)
	 {
       int nxt = s[i] - 'a';
       if (Trie[root].child[nxt] == -1)
			 {
			 	   Trie.push_back(Add_node());
			 	   Trie[root].child[nxt] = Trie.size() - 1;
			 }
			 root = Trie[root].child[nxt];
	 }
	 Trie[root].is_End = true;
}
void DFS(int u, int cnt)
{
	  if (Trie[u].is_End == true)
		{
			 cnt++;
			 ans = max(ans,cnt);
		}
		for (int i = 0 ; i < 26; i++)
		{
			int v = Trie[u].child[i];
			if (v != -1) DFS(v,cnt);
		}
}
int main()
{

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> n;
		Trie.push_back(Add_node());
		for (int i = 1; i <= n; i++)
		{
			  cin >> st;
			  Add(st);
		}
		ans = 0;
		DFS(0,0);
		cout << ans;
		return 0;

}



