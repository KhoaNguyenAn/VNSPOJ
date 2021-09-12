#include <stdio.h>
#include <cstdio>
#include <iostream>
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
#include <cstdlib>
#include <stack>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ld long double
#define MAXN 1000010
#define MOD 1000000007ll

using namespace std;
const int N = 1e6+5;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
typedef pair <int,int> ii;
map <ll,ll> f1,f2;
int n, kq[50], dd[50];
int sl = 0;
bool b[20];
int res[10] = {0, 0, 2, 2, 4, 96, 1024, 2880, 81024, 770144};
void xuat()
{
    sl++;
    for (int j=1; j<=n; j++)
        cout<< kq[j]<<" ";
    cout << endl;
}
bool check(int s)
{
    for (int k = 2; k*k <= s; k++)
    if (s % k == 0) return false;
    return true;
}
void backtrack(int i)
{
    if (i>n)
		{
			if (check(kq[n]+kq[1])==true) xuat();
			else return;
		}
    for (int j=1; j<=n; j++)
        if (dd[j]==0 && check(kq[i-1]+j)== true)
        {
            dd[j]=1;
            kq[i]=j;
            backtrack(i+1);
            if (sl == 10000) return;
            dd[j]=0;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << res[n] << endl;
    n <<= 1;
    dd[1] = 1;
    kq[1] = 1;
    backtrack(2);
    //cout << sl;
}
