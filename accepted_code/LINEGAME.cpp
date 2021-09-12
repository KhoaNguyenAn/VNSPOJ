#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <math.h>
typedef long long ll;
const int N = 1e6 + 5;
using namespace std;
ll n , f[N][2] , a[N];
int main()
{
    cin >> n;
    for (ll i = 1; i <= n ; i++)
        cin >> a[i];
    f[0][0] = 0;
    f[0][1] = -1e18;
    for (ll i = 1; i <= n ; i++)
    {
        f[i][0] = max(f[i-1][1]-a[i],f[i-1][0]);
        f[i][1] = max(f[i-1][0]+a[i],f[i-1][1]);
    }
    cout << max(f[n][0],f[n][1]);
}
