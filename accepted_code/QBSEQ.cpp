#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int f[N][52], a[N] , n ,k;
int sub (int b, int c)
{
    int tmp = (b-c) % k;
    if (b-c < 0) return tmp + k ; else return tmp;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < k; j++)
            f[i][j] = -999;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0 ; j < k ; j++)
           f[i][j] = max(f[i-1][j],f[i-1][sub(j,a[i]%k)]+1);
    cout << f[n][0];
}
