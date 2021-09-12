	
#include <stdio.h>
//#include <conio.h>
#include <iostream>
main()
{
char ch,ch1;      
long t=0,c[13],a[13],KQ=0,x;
while(scanf("%c",&ch)>0&&ch!='\n')
  {                                                           
  if(ch!=' ')
    {
    if(ch=='1')
      {
      scanf("%c",&ch1);
      if(ch1==' ')
        {
        t++;
        a[t]=1;
        }
      else
        {
        t++;
        a[t]=10+ch1-48;
        }
      }    
    else
      {             
      t++;
      a[t]=ch-48;
      }
    }
  }
//for(long i=1;i<=t;i++)
  //printf("%ld ",a[i]);
c[0]=1;
for(long i=1;i<=t;i++)
  c[i]=c[i-1]*i;
for(long i=1;i<=t;i++)
  {
  KQ=KQ+(a[i]-1)*c[t-i];
  for(long j=i+1;j<=t;j++)
    if(a[j]>a[i])
      a[j]--;
  }
printf("%ld\n",KQ+1);  
scanf("%ld",&x);
x=x-1;
for(long i=1;i<=t;i++)
  a[i]=i;
for(long i=1;i<=t;i++)
  {
  long n=x/c[t-i];
  printf("%ld ",a[n+1]);
  for(long j=n+1;j<=t-i;j++)
    a[j]=a[j+1];
  x=x%c[t-i];
  }
//getch();
}    
               