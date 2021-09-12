#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const unsigned long long INF = 1LL << 63;
const int N = 3e5;
unsigned long long IT[4*N],n,m,a[N],j,sum,f[N];
deque <int> que;
void ITbuild(int idx,int l,int r)
{
		if (l==r)
		{
			 IT[idx] = INF;
			 return;
		}
		int mid = (l+r) >> 1;
		ITbuild(idx*2,l,mid);
		ITbuild(idx*2+1,mid+1,r);
}

void ITupdate(int idx,int l,int r,int pos,unsigned long long k)
{
		if (l == r)
		{
			 IT[idx] = k;
			 return;
		}
		int mid = (l+r) >> 1;
		if (pos > mid) ITupdate(idx*2+1,mid+1,r,pos,k);
		else ITupdate(idx*2,l,mid,pos,k);
		IT[idx] = min(IT[idx*2],IT[idx*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    j = 1; sum = 0;
    fill(IT,IT+N+1,INF);
    for (int i = 1; i <= n; i++)
		{
				cin >> a[i];
				if (a[i] > m)
				{
					cout << -1;
					return 0;
				}
				sum+=a[i];
				while (sum > m) sum-= a[j++];
				while (!que.empty() && a[que.back()] <= a[i])
				{
						ITupdate(1,1,n,que.back(),INF);
						que.pop_back();
				}
				while (!que.empty() && que.front()<j)
				{
					  ITupdate(1,1,n,que.front(),INF);
						que.pop_front();
				}
				if (que.empty()) ITupdate(1,1,n,i,a[i]+f[j-1]);
				else
				{
						ITupdate(1,1,n,que.front(),f[j-1]+a[que.front()]);
						ITupdate(1,1,n,i,f[que.back()] + a[i]);
				}
				que.push_back(i);
				f[i] = IT[1];
		}
		cout << f[n];
    return 0;
}
