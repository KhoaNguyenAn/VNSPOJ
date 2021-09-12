#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int par[N],n,m,cnt[N],u,v,c,mmax;
struct mang
{
    int x;
    int y;
    int z;
};
mang a[N];

bool comp(mang aa , mang bb)
{
    return aa.z < bb.z;
}

int getroot(int u)
{
    if (par[u] == -1) return u;
    par[u] = getroot(par[u]);
    return par[u];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> c;
        a[i].x = u;
        a[i].y = v;
        a[i].z = c;
    }
    sort(a+1,a+m+1,comp);
    fill(par+1,par+n+1,-1);
    fill(cnt+1,cnt+n+1,0);
    mmax = 0;
    for (int i = 1; i <= m; i++)
    {
        int uu = getroot(a[i].x);
        int vv = getroot(a[i].y);
        if (uu != vv)
        {
            mmax = max(mmax,a[i].z);
            if (cnt[uu] > cnt[vv])
            {
                par[vv] = uu;
                cnt[uu] += cnt[vv];
            }
            else
            {
                par[uu] = vv;
                cnt[vv] += cnt[uu];
            }
        }
    }
    cout << mmax;
}