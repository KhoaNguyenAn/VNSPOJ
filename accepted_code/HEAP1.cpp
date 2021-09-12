#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long t,n;
    cin >> t;
    while (t--)
		{
			 cin >> n;
			 unsigned long long ans = 0;
			 priority_queue < unsigned long long,vector<unsigned long long>,greater<unsigned long long> >heap;
			 for (int i = 1; i <= n; i++) {int tmp; cin >> tmp; heap.push(tmp);}
			 for (int i = 1; i <= n-1;i++)
			 {
					unsigned long long xx = heap.top();
					heap.pop();
					unsigned long long yy = heap.top();
					heap.pop();
					ans+=xx+yy;
					heap.push(xx+yy);
			 }
			 while (!heap.empty()) heap.pop();
			 cout << ans << endl;
		}
    return 0;
}
