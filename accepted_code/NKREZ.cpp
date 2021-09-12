#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int f[N],n;
struct mang
{
    int x;
    int y;
    int z;
};
mang a[N];

bool comp(mang a1, mang b1)
{
    return a1.y < b1.y;
}
int chatnp(int l, int r , int ans)
{
    int res;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (a[mid].y <= ans)
        {
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].z = a[i].y - a[i].x;
    }
    sort(a+1,a+n+1,comp);
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = chatnp(0,i-1,a[i].x);
        f[i]=max(f[i-1],f[x]+a[i].z);
    }
    cout << f[n];
}
