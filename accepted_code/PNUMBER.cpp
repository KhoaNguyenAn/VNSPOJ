#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int a,b;
bool kt(int so)
{
    for (int j = 2; j <= sqrt(so); j++)
      if (so % j == 0) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    if (kt(i) && i != 1) cout << i << endl;
    return 0;
}
