#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int a[N],f[N],n,t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    a[0] = 0;
    a[1] = 1;
    for (int i = 1; i <= int(1e5); i++)
    if (i & 1) a[i] = a[i >> 1] + a[(i >> 1) + 1]; else a[i] = a[i >> 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 1; i <= int(1e5); i++) f[i] = max(f[i-1],a[i]);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        cout << f[t] << endl;
    }
    return 0;
}
