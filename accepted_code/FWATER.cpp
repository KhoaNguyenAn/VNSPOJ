#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <math.h>
using namespace std;

const long long inf  = 1e4 + 6;
const int N = 3e2+10;
int a[N][N],d[N],pos[N],h[N],x,sum,n,heap[N],n1;
void makeheap()
{
  int tmp;
  for (int i = n; i >= 1; i--)
  {
   tmp = i;
   while (tmp*2 <=n)
   {
    int tam = tmp;
    if (tmp*2 == n) tmp = tmp * 2;
    else
    if (tmp*2 < n)
    {
        if (d[heap[tmp*2]] <= d[heap[tmp*2+1]]) tmp = tmp*2; else tmp = tmp*2+1;
    }
    if (d[heap[tam]] > d[heap[tmp]])
     {
        swap(pos[heap[tam]],pos[heap[tmp]]);
        swap(heap[tam],heap[tmp]);
     }
     else break;
   }
  }
}

void pop()
{
  swap(pos[heap[1]],pos[heap[n1]]);
  swap(heap[1],heap[n1]);
  n1--;
  int tam1 = 1;
  int tam2;
  while (tam1 * 2 <= n1)
  {
    if (tam1 * 2 == n1)
      {
        tam2 = tam1 * 2;
      }
    else
    if (d[heap[tam1 * 2]] <= d[heap[tam1 * 2 + 1]]) tam2 = tam1 * 2; else tam2 = tam1 * 2 +1;
    if (d[heap[tam1]] > d[heap[tam2]])
    {
      swap(pos[heap[tam1]],pos[heap[tam2]]);
      swap(heap[tam1],heap[tam2]);
      tam1 = tam2;
    }
    else break;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)  cin >> d[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
          cin >> a[i][j];
  n1 = n;
  for (int i = 1; i <= n; i++)
    heap[i] = i;
  for (int i = 1; i <= n; i++)
    pos[i] = i;
  makeheap();
  sum = 0;
  for (int i = 1; i <= n; i++)
  {
     x = heap[1];
     h[x] = 1;
     sum+=d[x];
     pop();
     for (int j = 1; j <= n; j++)
     if (h[j] == 0)
     {
       int vt = pos[j];
       d[heap[vt]] = min(d[heap[vt]],a[x][j]);
       while (vt / 2)
       {
        if (d[heap[vt/2]] > d[heap[vt]])
        {
          swap(pos[heap[vt/2]],pos[heap[vt]]);
          swap(heap[vt/2],heap[vt]);
          vt = vt / 2;
        }
        else break;
       }
     }
  }
  cout << sum;
}
