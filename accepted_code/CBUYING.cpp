#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5 + 7;
ll n,p,res;
struct mang
{
    ll x;
    ll y;
};

bool comp(mang a1 , mang b1)
{
    return a1.x < b1.x;
}

mang a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    res = 0;
    for (ll i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    sort(a+1,a+n+1,comp);
    for (ll i = 1; i <= n; i++)
    if (p / a[i].x >= a[i].y)
    {
        p = p - (a[i].x*a[i].y);
        res += a[i].y;
    }
    else
    {
        res += p / a[i].x;
        break;
    }
    cout << res;
}
