#include <iostream>
#include <bits/stdc++.h>
#define INF 99999999999
#define ll long long
using namespace std;
const int N = 3*1e5+5;
ll res = INF,tmp,s1,s2,n,a1,b1;
struct ma
{
    ll x,y;
};
ma a[N];
bool cmp(ma A1,ma B1)
{
    return (A1.x < B1.x);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("MINROAD.INP","r",stdin);
    //freopen("MINROAD.OUT","w",stdout);
    cin >> n >> a1 >> b1;
    ll xx,yy;
    for (int i = 1; i <= n; i++)
    {
        cin >> xx >> yy;
        a[i].x = xx;
        a[i].y = yy;
    }
    sort(a+1,a+n+1,cmp);
    tmp = 1;
    s1 = 0; s2 = 0;
    for (int i = 1; i <= n; i++)
      if (a[i].y == 1) s1++; else s2++;
    if (s1 < a1 || s2 < b1)
    {
        cout << -1;
        return 0;
    }
    s1 = 0; s2 = 0;
    for (int i = 1; i <= n; i++)
    {
            if (a[i].y == 1) s1++; else s2++;
            while (s1 >= a1 && s2 >= b1 && tmp <= i)
            {
                res = min(res,abs(a[i].x-a[tmp].x));
                tmp++;
                if (a[tmp-1].y == 1) s1--; else s2--;
            }
    }
    cout << res;
    return 0;
}
