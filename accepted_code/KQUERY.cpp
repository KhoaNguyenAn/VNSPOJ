#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3*1e4+5;
const int Q = 2e5+4;
int n,q,xx,yy,zz,tmp,ans[Q];
struct mang1
{
        int x,y;
};
struct mang2
{
    int x,y,z,d;
};
struct segment
{
    mang1 a[N];
    mang2 c[Q];
    int b[N*4];
    void docfile()
    {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> xx;
        a[i].x = xx;
        a[i].y = i;
    }
    cin >> q;
    for (int i = 1; i <= q ; i++)
    {
        cin >> xx >> yy >> zz;
        c[i].x = xx;
        c[i].y = yy;
        c[i].z = zz;
        c[i].d = i;
    }
    }
    void update(int idx,int l,int r,int pos)
    {
      if (l == r)
      {
          b[idx]++;
          return;
      }
      int mid = (l+r) / 2;
      if (pos > mid) update(idx*2+1,mid+1,r,pos);
      else update(idx*2,l,mid,pos);
      b[idx] = b[idx*2] + b[idx*2+1];
    }
    int get(int idx,int l,int r,int L,int R)
    {
        if ((L<=l)&&(r<=R)) return b[idx];
        int mid = (l+r) / 2;
        if (L > mid) return get(idx*2+1,mid+1,r,L,R);
        else if (R <= mid) return get(idx*2,l,mid,L,R);
        return (get(idx*2+1,mid+1,r,L,R) + get(idx*2,l,mid,L,R));
    }
};
segment magic;
bool comp(mang2 a1, mang2 b1)
{
    return a1.z < b1.z;
}

bool comp1(mang2 a1, mang2 b1)
{
    return a1.d < b1.d;
}
bool comp3(mang1 a1, mang1 b1)
{
    return a1.x < b1.x;
}
int main()
{
    magic.docfile();
    sort(magic.a+1,magic.a+n+1,comp3);
    sort(magic.c+1,magic.c+q+1,comp);
    tmp= n;
     for (int i = q; i >= 1; i--)
    {
        while ((magic.a[tmp].x > magic.c[i].z) && (tmp > 0))
        {
             magic.update(1,1,n,magic.a[tmp].y);
             tmp--;
        }
        ans[magic.c[i].d] = magic.get(1,1,n,magic.c[i].x,magic.c[i].y);
    }
    for (int i = 1; i <= q; i++)
       cout << ans[i] << " ";
    return 0;
}
