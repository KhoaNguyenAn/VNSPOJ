#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1e6;
int i,bot,top,a[N],ans[N],dqueue[N],n,k;

void push_bck()
{
    bot++;
    dqueue[bot] = i;
}

int main()
{
    cin >> n;
    for (int l = 1 ; l <= n ; l++)
    {
        int n1,k;
        cin >> n1 >> k;
        for (int r = 1; r <= n1; r++)
        {
            cin >> a[r];
        }
        top = 1;
        bot = 0;
        i = 0;
        int j = 1;
        dqueue[0] = 0;
        a[0] = -1;
        while (i <= n1)
        {
            i++;
            if (a[i] > a[dqueue[bot]])
            {
                push_bck();
                if (dqueue[bot] - dqueue[top] >= k)
                {
                top++;
                }
            }
            else
            {
                while (a[i] <= a[dqueue[bot]])
                {
                    bot--;
                }
                push_bck();
                if (dqueue[bot] - dqueue[top] >= k)
                {
                top++;
                }
            }
            if (i-j+1 == k)
            {
                if (bot < top) top = bot;
                ans[j] = a[dqueue[top]];
                j++;
            }
        }
        for (int i = 1; i <= n1-k+1; i++)
            cout << ans[i] << ' ';
        cout << "\n";
     }
}


