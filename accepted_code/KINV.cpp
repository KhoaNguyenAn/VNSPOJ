#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#define ll long long
#define base 1000000000
using namespace std;
const int N = 1e4+5;
ll n,k,a[N],f[N][12],it[4*N],ans;

int get(int idx,int l,int r,int L,int R)
{
    if (L <= l && r <= R) return it[idx];
    int mid = (l+r) >> 1;
    if (L > mid) return get(idx*2+1,mid+1,r,L,R);
    else if (R <= mid) return (idx*2,l,mid,L,R);
    return ((get(idx*2+1,mid+1,r,L,R)%base + (get(idx*2,l,mid,L,R)%base))%base);
}

void update(int idx,int l,int r,int pos,ll val)
{
    if (l == r)
    {
        it[idx] = (it[idx] + val)%base;
        return;
    }
    int mid = (l+r) >> 1;
    if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
    else update(idx*2,l,mid,pos,val);
    it[idx] = (it[idx*2] + it[idx*2+1])%base;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n ; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) f[i][1] = 1;
    for (int j = 2; j <= k; j++)
    {
        memset(it,0,sizeof(it));
        for (int i = 1; i <= n; i++)
        {
            f[i][j] = get(1,1,n,a[i]+1,n);
            update(1,1,n,a[i],f[i][j-1]);
        }
    }
    ans = 0;
    for (int i = 1; i <= n ; i++) ans = (ans + f[i][k]) % base;
    cout << ans;
    return 0;
}
