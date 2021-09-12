#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <map>
 
using namespace std;
 
#define X first
#define Y second
#define INPUT freopen("dttui1.inp","r",stdin)
#define OUTPUT freopen("dttui1.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1
 
typedef long long ll;
typedef pair<int,int> ii;
 
const int inf=2e9;
const int MOD=1e9+7;
const int N=40;
 
ii f[1<<20],a[N];
int w[1<<20],c[1<<20],n;
ll m;
void prepare(){
    scanf("%d%lld",&n,&m);
    REP(i,0,n) scanf("%d%d",&a[i].X,&a[i].Y);
}
void solve(){
    int k=1<<(n/2);
    REP(i,0,n/2) f[1<<i]=ii(a[i].X,a[i].Y);
    REP(i,1,k){
        int x=i^(i&-i);
        f[i]=ii(f[i&-i].X+f[x].X,f[i&-i].Y+f[x].Y);
    }
    sort(f,f+k);
    int tmp=0;
    REP(i,1,k){
        f[++tmp]=f[i];
        f[tmp].Y=max(f[tmp].Y,f[tmp-1].Y);
        while (i<k-1&&f[i+1].X==f[tmp].X){
            i++;
            f[tmp].Y=max(f[tmp].Y,f[i].Y);
        }
    }
    k=tmp+1;
    int c1=1<<((n+1)/2);
    REP(i,0,(n+1)/2) {
        w[1<<i]=a[n/2+i].X;
        c[1<<i]=a[n/2+i].Y;
    }
    int ans=0;
    REP(i,0,c1){
        if (i){
            int x=i^(i&-i);
            w[i]=w[x]+w[i&-i];
            c[i]=c[x]+c[i&-i];
        }
        if (w[i]>m) continue;
        int L=0,R=k-1;
        while (L<=R){
            int M=(L+R)>>1;
            if (m-w[i]>=f[M].X) L=M+1;
            else R=M-1;
        }
        //printf("%d %d %d %d\n",i,w[i],c[i],L-1);
        ans=max(ans,c[i]+f[L-1].Y);
    }
    cout<<ans;
}
int main(){
    //INPUT;
    prepare();
    solve();
}