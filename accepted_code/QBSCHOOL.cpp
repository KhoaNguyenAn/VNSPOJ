#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define X first
#define Y second
#define INF 999999999
using namespace std;
const int N = 2 * 1e4 + 5005;
#define ll long long
typedef pair <ll,ll> ii;
priority_queue <ii> que;
vector <ii> a[N];
ll n,m,k,u,v,seen[N],d[N],f[N],l,ans;
struct mang
{
    ll x1;
    ll y1;
};
mang d1[N];

bool comp(mang a1 , mang b1)
{
    return a1.x1 < b1.x1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> k >> u >> v >> l;
        if (k == 1)
        {
            a[u].push_back(ii(l,v));
        }
        else
        {
            a[u].push_back(ii(l,v));
            a[v].push_back(ii(l,u));
        }
    }
    fill(seen+1,seen+n+1,0);
    fill(d+1,d+n+1,INF);
    d[1] = 0;
    f[1] = 1;
    que.push(ii(0,1));
    while (!que.empty())
    {
        ii x = que.top();
        que.pop();
        if (seen[x.Y] == 1) continue;
        seen[x.Y] = 1;
        for (int i = 0; i < a[x.Y].size(); i++)
        {
            ii tmp = a[x.Y][i];
           // if (d[tmp.Y] == tmp.X + d[x.Y])
             //   f[tmp.Y] += f[tmp.X];
            if (d[tmp.Y] > tmp.X + d[x.Y])
            {
                d[tmp.Y] = tmp.X + d[x.Y];
         //       f[tmp.Y] = f[tmp.X];
                que.push(ii(-d[tmp.Y],tmp.Y));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        d1[i].x1 = d[i];
        d1[i].y1 = i;
    }
    sort(d1+1,d1+n+1,comp);
    f[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        mang tmp = d1[i];
        for (int j = 0; j < a[tmp.y1].size(); j++)
        {
            ii x2 = a[tmp.y1][j];
            if (d[x2.Y] == d[tmp.y1] + x2.X)
                f[x2.Y] += f[tmp.y1];
        }
    }
    cout << d[n] << " " << f[n];
}



