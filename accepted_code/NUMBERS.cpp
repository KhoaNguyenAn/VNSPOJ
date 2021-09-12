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
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define base 27ll
#define MAXN 1000010
#define MOD 1000000007ll

using namespace std;
const int N = 1e6+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
map <int,int> lua;
vector <int> b[N];
int f[N],a[N],sz,mm,vt,n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	sz = 0;
	for (int i = 1; i <= n; i++)
	if (a[i]==a[i-1])
	{
		f[a[i]] = f[a[i]] + 1;
		b[f[a[i]]].push_back(a[i]);
		sz = max(sz,f[a[i]]);
	}
	else
	{
		mm = 0;
		vt = 0;
		for (int j = 1; j*j <= a[i]; j++)
		if (a[i] % j == 0 && f[j] > mm)
		{
			mm = f[j];
			vt = j;
			if (f[a[i]/j] > mm) {mm = f[a[i]/j]; vt = a[i]/j;}
		}
		else if (a[i] % j == 0 && f[a[i]/j] > mm)
		{
			mm = f[a[i]/j];
			vt = a[i]/j;
		}
		f[a[i]] = f[vt] + 1;
		b[f[a[i]]].push_back(a[i]);
		sz = max(sz,f[a[i]]);
	}
	cout << sz << endl;
	for (int i = 1; i <= sz; i++)
	{
		cout << b[i].size() << " ";
		for (int j = 0; j < b[i].size(); j++) cout << b[i][j] << " ";
		cout << "\n";
	}
	return 0;
}