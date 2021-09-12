#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define base 111539786
#define ll long long
const int N = 10;
using namespace std;
int n,t;
int A[2][2] =
{
    {1,1},
    {1,0},
};
int f[2][1] =
{
    {1},
    {1}
};
int I[2][2] =
{
    {1,0},
    {0,1}
};
struct ds
{
    ll d[N][N];
    int m1,n1;
    ds() {memset(d,0,sizeof(d));}
};
ds operator * (ds A1, ds B1)
{
    ds C;
    C.n1 = B1.m1;
    C.m1 = A1.n1;
    for (int i = 0; i < C.n1; i++)
      for (int j = 0; j < C.m1; j++)
        {
           C.d[i][j] = 0;
           for (int k = 0; k < A1.m1; k++)
               C.d[i][j] = (C.d[i][j] + (A1.d[i][k] * B1.d[k][j])) % base;
        }
    return C;
}
ds ans,cur,ok;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    ans.m1 = 2;
    ans.n1 = 2;
    cur.m1 = 2;
    cur.n1 = 2;
    ok.m1 = 1;
    ok.n1 = 2;
    for (int i = 0; i < 2; i++)
     for (int j = 0; j < 1; j++)
        ok.d[i][j] = f[i][j];
    while (t--)
    {
        cin >> n;
        n--;
        for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
           ans.d[i][j] = I[i][j];
           cur.d[i][j] = A[i][j];
        }
        while (n > 0)
        {
           if (n & 1) ans = ans*cur;
           cur = cur * cur;
           n >>= 1;
        }
        ds res = ans * ok;
        cout << res.d[0][0] << "\n";
    }
    return 0;
}
