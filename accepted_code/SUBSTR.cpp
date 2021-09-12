#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int N = 2*1e6 + 4;
string a,b,c;
int t[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;
    c = b + '#' + a;
    int n = c.size();
    t[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int len = t[i-1];
        while (c[i] != c[len] && len > 0)
            len = t[len-1];
        if (c[i] == c[len]) len++;
        t[i] = len;
    }
    for (int i = 0; i < n; i++)
        if (t[i] == b.size()) cout << i - (2*t[i]) + 1 << ' ';
}
