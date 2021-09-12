#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
#define ll unsigned long long
#define INF 1e18
using namespace std;
ll n,tmp,kq;
ll power(int xx, int yy)
{
        ll ans = 1;
        ll cur = xx;
        while (yy > 0)
        {
             if (yy & 1)
             {
               if (n/ans < cur) return INF;
               ans = ans * cur;
             }
                         if (n/cur < cur) cur = INF+1;else cur*=cur;
             yy >>= 1;
        }
        return ans;
}
ll cnp(ll x)
{
     ll l = 1;
     ll r = int(1e9)+1;
     ll mid,k;
     while (l < r)
     {
            mid = (l+r) >> 1;
            k = power(mid,x);
            if (k==n) return mid;
            if (k > n)
                r = mid-1; else l = mid+1;
     }
     return r;
}
bool kt(ll xxx)
{
      if (xxx == 1) return false;
        ll tam = sqrt(xxx);
        for (int j = 2; j <= tam; j++)
        if (xxx % j == 0) return false;
        return true;
}
int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        int tmp = 60;
        for (int i = 2; i <= tmp; i++)
        {
             kq = cnp(i);
             if (power(kq,i) == n)
             if (kt(kq) == true)
             {
                    cout << kq << " " << i;
                    return 0;
             }
        }
        cout << 0;
        return 0;
}
