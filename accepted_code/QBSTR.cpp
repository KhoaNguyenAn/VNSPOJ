#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
unsigned long long n1,n2,f[3000][3000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    s1 = '.' + s1;
    s2 = '.' + s2;
    unsigned long long n1 = s1.size()-1;
    unsigned long long n2 = s2.size()-1;
    memset(f,0,sizeof(f));
    for (int i = 1; i <= n1; i++)
      for (int j = 1; j <= n2; j++)
        {
            if (s1[i] == s2[j]) f[i][j] = f[i-1][j-1]+1;
                else f[i][j] = max(f[i-1][j],f[i][j-1]);
        }
    cout << f[n1][n2];
    return 0;
}
