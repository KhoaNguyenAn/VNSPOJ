#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef pair <int,int> ii;
const int N = 1e2 +5;
const ii d1[4] = {ii(0,-1),ii(0,1),ii(1,0),ii(-1,0)};
#define X first
#define Y second
int x1,y1,n,m,d[N][N];
char a[N][N];
bool seen[N][N];
queue <ii> que;
void bfs()
{
    seen[x1][y1] = true;
    que.push(ii(x1,y1));
    while (!que.empty())
    {
        ii tmp = que.front();
        que.pop();
        for (int i = 0; i < 4 ; i++)
        {
            int x = tmp.X + d1[i].X;
            int y = tmp.Y + d1[i].Y;
            if (x > 0 && x <= n && y > 0 && y <= m)
             if (a[x][y] != '*' && seen[x][y] == false)
            {
                que.push(ii(x,y));
                seen[x][y] = true;
                d[x][y] = d[tmp.X][tmp.Y] + 1;
                if (x == 1 && y == 1) return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n ; i++)
      for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'C')
            {
                x1 = i;
                y1 = j;
            }
        }
    bfs();
    cout << d[1][1];
}
