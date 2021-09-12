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
const int N = 1e5+6;
const int INF = 1e9 + 10;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
map <int,int> lua;
struct cmp
{
		bool operator() (ii A1,ii B1)
		{
			return A1.Y < B1.Y;
		};
};
set <ii,cmp> s;
set <ii,cmp>::iterator add;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		int n,x,y;
		cin >> n;
		if (n == 0) return 0;
		if (n == 1)
		{
				cin >> x >> y;
				s.insert(ii(x,y));
		}
		else
		if (n == 2)
		{
				if (!s.empty())
				{
						add = s.end();
						add--;
						cout << add -> X << endl;
						s.erase(add);
				}
				else cout << 0 << endl;
		}
		else
		{
				if (!s.empty())
				{
					 add= s.begin();
					 cout << add -> X << endl;
					 s.erase(add);
				}
				else cout << 0 << endl;
		}
	}
	return 0;
}