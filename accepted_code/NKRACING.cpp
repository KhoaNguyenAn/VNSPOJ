#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstring>
const int N = int(1e5) + 7;
using namespace std;
int n , m, p[N],c[N],s[N];

struct mang
{
   int x;
   int y;
   int w;
};
mang a[N];

int comp(mang a, mang b)
{
    return a.w > b.w;
}

int getroot(int x)
{
    if (p[x]==0) return x;
    p[x] = getroot(p[x]);
    return p[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= m ; i++)
    {
       cin >> a[i].x >> a[i].y >> a[i].w;
       sum+=a[i].w;
    }
    int ans = 0;
    sort(a+1,a+m+1,comp);
    fill(s+1,s+n+1,1);
    for (int i = 1; i <= m; i++)
    {
       int x1 = getroot(a[i].x);
       int y1 = getroot(a[i].y);
       if (x1 != y1)
       {
        c[i] = 1;
        if (s[x1] <= s[y1])
        {
          p[x1] = y1;
          s[y1] += s[x1];
        }
        else
        if (s[x1] > s[y1])
        {
          p[y1] = x1;
          s[x1]+=s[y1];
        }
       }
    }
    for (int i = 1; i <= m; i++)
      if (c[i] == 1) ans += a[i].w;
    cout << sum - ans;
}

