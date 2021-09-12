#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
const int N = 5*1e4 + 5;
#define X first
#define Y second
typedef pair <int,int> ii;
priority_queue <ii,vector<ii>, greater<ii>> heap;
int n,m,k,a[N],b[N],l[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n ; i++)
     cin >> a[i];
    for (int i = 1; i <= m ; i++)
     cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for (int i = 1; i <= n; i++)
        heap.push(ii(a[i]+b[1],i));
    int j = 1;
    int dem = m;
    while (k--)
    {
        ii x = heap.top();
        cout << x.X << endl;
        int i = x.Y;
        heap.pop();
        l[i]++;
        if (l[i] < m) heap.push(ii(a[i]+b[l[i]+1],i));
    }
    return 0;
}
