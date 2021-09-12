#include <iostream>
#include <stdio.h>
#include <math.h>
typedef long long ll;
const int N = 4000000 + 9;
using namespace std;
int a[N],i,f1[N],f2[N],n,f[N],stk[N],t1[N],t2[N];

void frut_right()
{
    int top = 0;
    stk[top] = n + 1;
    i = n+1;
    int tmp;
    while (i != 1)
    {
        i--;
        tmp = i + a[i] - 1;
        while (top > 0 && stk[top] <= tmp)
        {
            top--;
        }
        f1[i] = stk[top] - 1;
        top++;
        stk[top] = i;
    }
}

void frut_left()
{
    int top = 0;
    stk[top] = 0;
    i = 0;
    int tmp;
    while (i != n)
    {
        i++;
        tmp = i - a[i] + 1;
        while (top > 0 && stk[top] >= tmp)
        {
            top--;
        }
        f2[i] = stk[top] + 1;
        top++;
        stk[top] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("","r",stdin);
//    freopen("","w",stdout);
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    frut_right();
    frut_left();
    f[0] = 0;
    for (int i = 1 ; i <= n; i++)
    {
        f[i] = (1 << 31) - 1;
    }
    int top = 1;
    stk[top] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[f1[i]] > f[i-1] + 1)
        {
            t2[f1[i]] = i - 1;
            t1[f1[i]] = i;
            f[f1[i]] = f[i-1] + 1;
        }
        while (top > 0 && stk[top] >= f2[i] - 1)
        {
            top--;
        }
        if (top + 1 < f[i])
        {
            f[i] = top + 1;
            t1[i] = -i;
            t2[i] = stk[top + 1];
        }
        top = f[i]+1;
        stk[top] = i;
    }
    cout << f[n];
    cout << "\n";
    int tam = n;
    while (tam != 0)
    {
        cout << t1[tam] << ' ';
        tam = t2[tam];
    }
}
