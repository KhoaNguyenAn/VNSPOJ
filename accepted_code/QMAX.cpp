#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+2;
int n,m,u,v,k,a[N],mmax[N],q;
void build(int idx,int l, int r)
{
    if (l==r)
    {
        mmax[idx] = a[l];
        return;
    }
    int mid = (l+r) / 2;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    mmax[idx] = max(mmax[idx*2],mmax[idx*2+1]);
}
int get(int idx,int l,int r,int L,int R)
{
    if ((L<=l)&&(r<=R)) return mmax[idx];
    int mid = (l+r) / 2;
    if (L > mid) return get(idx*2+1,mid+1,r,L,R);
    else
    if (R <= mid) return get(idx*2,l,mid,L,R);
    return max(get(idx*2,l,mid,L,R),get(idx*2+1,mid+1,r,L,R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> k;
        a[u] += k;
        a[v+1] -= k;
    }
    for (int i = 1; i <= n;i++)
        a[i] += a[i-1];
    build(1,1,n);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v;
        cout << get(1,1,n,u,v) << "\n";
    }
    return 0;
}
