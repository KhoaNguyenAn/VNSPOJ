#include <iostream>
#include <bits/stdc++.h>
#define ll long long
const int N = 5*1e4+3;
using namespace std;
int n,m,a[N],x,y;
struct mang
{
    ll left,right,sum,ans;
};
mang mmax[4*N];
void build(int idx,int l,int r)
{
    if (l==r)
    {
        mmax[idx].sum = a[l];
        mmax[idx].left = a[l];
        mmax[idx].right= a[l];
        mmax[idx].ans = a[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(idx*2,l,mid);
    build(idx*2+1,mid+1,r);
    mmax[idx].sum = mmax[idx*2].sum + mmax[idx*2+1].sum;
    mmax[idx].left = max(mmax[idx*2].left,mmax[idx*2].sum+mmax[idx*2+1].left);
    mmax[idx].right = max(mmax[idx*2+1].right,mmax[idx*2+1].sum+mmax[idx*2].right);
    mmax[idx].ans = max(max(mmax[idx*2].ans,mmax[idx*2+1].ans),mmax[idx*2].right+mmax[idx*2+1].left);
}
mang get(int idx,int l,int r,int L,int R)
{
    if ((L<=l) &&(r<=R)) return mmax[idx];
    int mid = (l+r) >> 1;
    if (L > mid) return get(idx*2+1,mid+1,r,L,R);
    else if (R <= mid) return get(idx*2,l,mid,L,R);
    mang tmp1 = get(idx*2,l,mid,L,R);
    mang tmp2 = get(idx*2+1,mid+1,r,L,R);
    mang tmp;
    tmp.left = max(tmp1.left,tmp1.sum+tmp2.left);
    tmp.right = max(tmp2.right,tmp2.sum+tmp1.right);
    tmp.sum = tmp1.sum + tmp2.sum;
    tmp.ans = max(max(tmp1.ans,tmp2.ans),tmp1.right+tmp2.left);
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(mmax,0,sizeof(mmax));
    for (int i = 1; i <= n; i++)
     cin >> a[i];
    build(1,1,n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        cout << get(1,1,n,x,y).ans << endl;
    }
    return 0;
}
