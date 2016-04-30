#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
 int t,i,n,count=0;
 scanf("%d",&t);
 char c[1001];
 while(t--)
 {
  scanf("%d\n",&n);
  gets(c);
  count=0;
  for(i=0;i<n;i++)
   {
    if(i==0&&c[i]!='1'&&c[i+1]!='1')
     count++;
    else if(i==(n-1)&&c[i]!='1'&&c[i-1]!='1')
     count++;
    else if(c[i]!='1'&&c[i-1]!='1'&&c[i+1]!='1')
     count++;
   }
  printf("%d\n",count);
 }
 return 0;
}  
