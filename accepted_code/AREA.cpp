#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
//#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define MOD 1000000007
#define INPUT freopen("area.inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int N=10010;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

iii a[N<<1];
int p[N<<3]={0},h[30010]={0},b[N<<1],c[N<<3]={0},x1,x2,y1,y2,n,top=0;
void prepare()
{
    scanf("%d",&n);
    REP(i,0,n)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==x2||y1==y2) {n--;i--;continue;}
        if (h[y1]==0) {b[++top]=y1;h[y1]=1;}
        if (h[y2]==0) {b[++top]=y2;h[y2]=1;}
        a[2*i+1].X=x1,a[2*i+1].Y.X=y1,a[2*i+1].Y.Y=y2;
        a[2*i+2].X=x2,a[2*i+2].Y.X=y2,a[2*i+2].Y.Y=y1;
    }
    sort(a+1,a+2*n+1);
    sort(b+1,b+top+1);
}
void add(int y1,int y2,int node,int l,int r)
{
    if (y1>=b[r]||y2<=b[l]) return;
    if (y1<=b[l]&&y2>=b[r])
    {
        p[node]=b[r]-b[l];
        c[node]++;
        return;
    }
    if (l+1>=r) return;
    add(y1,y2,node*2,l,(l+r)/2);
    add(y1,y2,node*2+1,(l+r)/2,r);
    if (c[node]==0) p[node]=p[node*2]+p[node*2+1];
}
void close(int y1,int y2,int node,int l,int r)
{
    if (y1>=b[r]||y2<=b[l]) return;
    if (y1<=b[l]&&y2>=b[r])
    {
        c[node]--;
        if (c[node]==0) if (l+1<r) p[node]=p[node*2]+p[node*2+1];else p[node]=0;
        return;
    }
    if (l+1>=r) return;
    close(y1,y2,node*2,l,(l+r)/2);
    close(y1,y2,node*2+1,(l+r)/2,r);
    if (c[node]==0) p[node]=p[node*2]+p[node*2+1];
}
void solve()
{
    int ans=0;
    FOR(i,1,2*n)
    {
        ans+=p[1]*(a[i].X-a[i-1].X);
        if (a[i].Y.X<a[i].Y.Y) add(a[i].Y.X,a[i].Y.Y,1,1,top);
        else close(a[i].Y.Y,a[i].Y.X,1,1,top);
    }
    printf("%d\n",ans);
}
int main()
{
    //INPUT;
    prepare();
    solve();
}
