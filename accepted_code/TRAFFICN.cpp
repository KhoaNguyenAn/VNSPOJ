#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#define X first
#define Y second
#define INF 999999999
using namespace std;
const int N = 1e5 + 7;
typedef pair <int,int> ii;
priority_queue <ii> que;
vector <ii> a[N],b[N];
int q,n,m,k,s,t,d1[N],d2[N],ans,u,v,c,x,y,w1;
bool seen[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> n >> m >> k >> s >> t;
        for (int i1 = 1 ; i1 <= n; i1++)
        {
            a[i1].clear();
            b[i1].clear();
        }
        for (int l = 1 ; l <= m; l++)
        {
            cin >> u >> v >> c;
            a[u].push_back(ii(c,v));
            b[v].push_back(ii(c,u));
        }
        ans = INF;
        fill(d1+1,d1+n+1,INF);
        fill(seen+1,seen+n+1,false);
        d1[s] = 0;
        que.push(ii(0,s));
        while (!que.empty())
        {
            ii x = que.top();
            que.pop();
            if (seen[x.Y] == true) continue;
            seen[x.Y] = true;
            for (int j = 0; j < a[x.Y].size(); j++)
            {
                ii tmp = a[x.Y][j];
                if (d1[tmp.Y] > tmp.X + d1[x.Y])
                {
                    d1[tmp.Y] = tmp.X + d1[x.Y];
                    que.push(ii(-d1[tmp.Y],tmp.Y));
                }
            }
        }
        fill(d2+1,d2+n+1,INF);
        fill(seen+1,seen+n+1,false);
        d2[t] = 0;
        que.push(ii(0,t));
        while (!que.empty())
        {
            ii x = que.top();
            que.pop();
            for (int j = 0; j < b[x.Y].size(); j++)
            {
                ii tmp = b[x.Y][j];
                if (d2[tmp.Y] > tmp.X + d2[x.Y])
                {
                    d2[tmp.Y] = tmp.X + d2[x.Y];
                    que.push(ii(-d2[tmp.Y],tmp.Y));
                }
            }
        }
        ans = min(ans,d1[t]);
        for (int k1 = 1; k1 <= k; k1++)
        {
            cin >> x >> y >> w1;
            ans = min(ans,min(d1[x]+d2[y]+w1,d1[y]+d2[x]+w1));
        }
        if (ans != INF)
        cout << ans << "\n"; else cout << -1 << "\n";
    }
    return 0;
}
