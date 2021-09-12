#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
const int MAX = 11000;
const int N = 1e8;
int b[N],res[N],prime[N],x,snt[N],sl;
/*void sang_era()
{
		fill(snt,snt+3000,true);
		sl = 0;
		snt[0] = false; snt[1] = false;
		for (int i = 2; i <= MAX; i++)
		 if (snt[i] == true)
			{
				for (int j = 2; j <= MAX/i; j++) snt[i*j] = false;
			}
		for (int i = 2; i <= MAX; i++) if (snt[i] == true)
		{
				sl++;
				prime[sl] = i;
		}
}
*/
void Eratosthene(){
	fill(snt,snt+3000,true); sl = 0;
	for(int i = 2; i < MAX; i++) snt[i] = 1;
	snt[0] = snt[1] = 0;
	for(int i = 2; i*i < MAX; i ++)
		if(snt[i])
			for(int j = i*i; j < MAX; j += i)
				snt[j] = 0;
	for(int i = 0; i < MAX; i++) if(snt[i] == true) {sl++; prime[sl] = i;};
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //sang_era();
		Eratosthene();
    b[0] = 0;
    for (int i = 1; i <= sl; i++)
			b[i] = b[i-1] + prime[i];
		memset(res,0,sizeof(res));
		for (int i = 1; i <= sl; i++)
			for (int j = i; j <= sl; j++)
				 res[b[j] - b[i-1]]++;
    while (true)
		{
				cin >> x;
				if (x == 0) return 0;
				cout << res[x] << "\n";
		}
    return 0;
}
