#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e4+2;
const int N1 = 1e6+5;
int b[N1],ans[N1],n,sl,q,a[N],xx,yy,tree[4*N];
struct mang1
{
    int l,r,x;
};
mang1 c[N1];
bool comp(mang1 a2, mang1 b2) {return (a2.r < b2.r);}
void update(int idx, int l, int r, int pos, int val)
{
    if (l == r)
    {
        tree[idx] += val;
        return;
    }
    int mid = (l+r) >> 1;
    if (pos > mid) update(idx*2+1,mid+1,r,pos,val);
    else update(idx << 1,l,mid,pos,val);
    tree[idx] = tree[idx << 1] + tree[idx*2+1];
}

int get(int idx, int l , int r, int L, int R)
{
    if (L <= l && r <= R) return tree[idx];
    int mid = (l+r) >> 1;
    if (L > mid) return get(idx*2+1,mid+1,r,L,R);
    else if (R <= mid) return get(idx << 1,l,mid,L,R);
    return (get(idx*2+1,mid+1,r,L,R)+get(idx << 1,l,mid,L,R));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = 0;
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> xx >> yy;
        c[i].l = xx;
        c[i].r = yy;
        c[i].x = i;
    }
    sort(c+1,c+q+1,comp);
    for (int i = 1; i <= n; i++) update(1,1,n,i,1);
    int j = 1;
    for (int i = 1; i <= q; i++)
    {
      while (j <= c[i].r)
      {
          if (b[a[j]] != 0) update(1,1,n,b[a[j]],-1);
          b[a[j]] = j;
          j++;
      }
      ans[c[i].x] = get(1,1,n,c[i].l,c[i].r);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
