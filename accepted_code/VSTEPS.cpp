#include <iostream>
#include <stdio.h>
#define base 14062008
using namespace std;
const int N = 1e5 + 7;
int n,k,f[N],v;
bool a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(a+1,a+n+1,true);
    for (int i = 1; i <= k; i++)
    {
        cin >> v;
        a[v] = false;
    }
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
      if (a[i-1] == false && a[i-2] == true)
        f[i] = f[i-2];
      else
      if (a[i-1] == true && a[i-2] == false)
        f[i] = f[i-1];
      else f[i] = (f[i-1] + f[i-2]) % base;
      if (a[i] == false && a[i-1] == false)
      {
          cout << 0;
          return 0;
      }
    }
    cout << f[n];
}
