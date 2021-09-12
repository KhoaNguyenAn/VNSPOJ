///Kaze
#include <bits/stdc++.h>
#include <iostream>
#define taskname "QTSEQ"
#define Eureka cerr << "Eureka"
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;
const ll N = 1e6 + 2;
const ll INF = 1e9 + 10;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e10 + 13;
const ll base = 311;
queue <int> que;
long long n,a[N],pre[N],suf[N],mmin[N],mmax[N],res,cnt1[N],cnt2[N],cnt;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
int main()
{
		read(n);
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
		  pre[i] = pre[i-1]+a[i];
		for (int i = 0; i <= n + 1; i++)
			mmin[i] = INF64, mmax[i] = -INF64;
		for (int i = n; i >= 1; i--)
		{
			suf[i] = suf[i+1]+a[i];
			mmin[i] = min(suf[i],mmin[i+1]);
			mmax[i] = max(suf[i],mmax[i+1]);
		}
		for (int i = n; i >= 1; i--)
		{
			if (suf[i] == mmax[i+1]) cnt1[i] = cnt1[i+1] + 1;
			else
			if (suf[i] > mmax[i+1]) cnt1[i] = 1;
			else cnt1[i] = cnt1[i+1];
		  if (suf[i] == mmin[i+1]) cnt2[i] = cnt2[i+1] + 1;
			else
			if (suf[i] < mmin[i+1])cnt2[i] = 1;
			else cnt2[i] = cnt2[i+1];
		}
		res = 0;
		for (int i = 1; i < n; i++)
		{
			 res = max(res,abs(pre[i]-mmin[i+1]));
			 res = max(res,abs(pre[i]-mmax[i+1]));
		}
		for (int i = 1; i < n; i++)
		{
	  if (abs(pre[i]-mmin[i+1])==res) cnt+=cnt2[i+1];
	  if (mmin[i + 1] != mmax[i + 1] && abs(pre[i]-mmax[i+1])==res) cnt+=cnt1[i+1];
		}
		Write(res);
		putchar(' ');
		Write(cnt);
		return 0;
}
/**Code written by AnkhoaGD**/