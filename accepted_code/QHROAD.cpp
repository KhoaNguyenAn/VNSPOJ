#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#define INF 99999999

using namespace std;
const int N = 1e5 + 3;
typedef long long ll;
int a[N][2],par[N],cnt[N],b[N],ans,n,m,q,u,v;
bool c[N];
vector <int> d;

int getroot(int x)
{
    if (par[x] == -1) return x;
    par[x] = getroot(par[x]);
    return par[x];
}

void disjoinset(int x1 , int y1)
{
    int x2 = getroot(x1);
    int y2 = getroot(y1);
    if (x2 != y2)
    {
        ans--;
        if (cnt[x2] >= cnt[y2])
        {
            par[y2] = x2;
            cnt[x2] += cnt[y2];
        }
        else
        {
            par[x2] = y2;
            cnt[y2] += cnt[x2];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m ; i++)
    {
        cin >> u >> v;
        a[i][0] = u;
        a[i][1] = v;
    }
    fill(c,c+m+1,true);
    for (int i = 1; i <= q; i++)
    {
        cin >> b[i];
        c[b[i]] = false;
    }
    ans = n;
    fill(cnt,cnt+n+1,1);
    fill(par,par+n+1,-1);
    for (int i = 1; i <= m; i++)
    if (c[i] == true)
    {
        disjoinset(a[i][0],a[i][1]);
    }
    for (int i = q; i >= 1 ; i--)
    {
        d.push_back(ans);
        disjoinset(a[b[i]][0],a[b[i]][1]);
    }
    reverse(d.begin(),d.end());
    for (int i = 0; i < q ; i++)
        cout << d[i] << "\n";
}
