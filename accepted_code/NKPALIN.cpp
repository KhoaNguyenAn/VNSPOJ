#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int N = 2*1e3 + 7;
string st,st1,st2;
int f[N][N],trace1[N][N],trace2[N][N],tam,tam1,tam2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> st;
    int n = st.length() - 1;
    st1 = "";
    st2 = "";
    for (int i = n; i >= 0;i--)
        for (int j = i; j <= n;j++)
            if (i == j)
            {
                f[i][j] = f[i+1][j-1] + 1;
                trace1[i][j] = i + 1;
                trace2[i][j] = j - 1;
            }
            else
            if (st[i] == st[j])
            {
                f[i][j] = f[i+1][j-1] + 2;
                trace1[i][j] = i + 1;
                trace2[i][j] = j - 1;
            }
            else
            {
                 f[i][j] = max(f[i][j-1],f[i+1][j]);
                 if (f[i][j-1] >= f[i+1][j])
                 {
                         trace1[i][j] = i;
                         trace2[i][j] = j-1;
                 }
                 else
                 {
                         trace1[i][j] = i+1;
                         trace2[i][j] = j;
                 }
            }
      tam1 = 0;
      tam2 = n;
      while (1)
      {
       int tam = tam1;
       tam1 = trace1[tam1][tam2];
       tam2 = trace2[tam][tam2];
       if (tam1 <= tam2)
       {
       if (tam1 != tam2 && st[tam1] == st[tam2])
       {

        st1 = st1 + st[tam1];
        st2 = st[tam2] + st2;
       }
       if (tam1 == tam2)
        st1 = st1 + st[tam1];
       } else break;
      }
      if (st[0]==st[n]) cout << st[0]+st1+st2+st[n]; else cout << st1 + st2;
}
