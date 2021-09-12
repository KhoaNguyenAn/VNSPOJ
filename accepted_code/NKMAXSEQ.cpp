#include <iostream>
#define INF 999999999
using namespace std;
const int N = 1e6*2;
int a[N],n,k,b[N],top,mmax,i;
struct mang
{
    int X;
    int Y;
};
mang f[N];

int chatnp(int l, int r)
{
    int res = -INF;
    while (l <= r)
    {
        int mid = (l+r) / 2;
        int ans = b[i] - f[mid].X;
        if (ans >= k)
        {
            r = mid-1;
            res = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
       cin >> a[i];
       b[i] = b[i-1] + a[i];
    }
    f[0].X = 0;
    f[0].Y = 0;
    top = 0;
    mmax = -1;
    for (i = 1; i <= n; i++)
    {
       if (b[i] < f[top].X)
       {
           top++;
           f[top].X = b[i];
           f[top].Y = i;
       }
           int j = chatnp(0,top);
           if (j != -INF)
             mmax = max(mmax,i-f[j].Y);
    }
    cout << mmax;
    return 0;
}
