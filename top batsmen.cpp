#include <iostream>
#include <stdio.h>
#include<algorithm>
 
using namespace std;
 
int factorial(int n)
{
   int c;
   int result = 1;
 
   for( c = 1 ; c <= n ; c++ )
      result = result*c;
 
   return ( result );
}
 
int find_ncr(int n, int r)
{
   int result;
 
   result = factorial(n)/(factorial(r)*factorial(n-r));
 
   return result;
}
 
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[11],i;
        for(i=0;i<11;i++) scanf("%d",&a[i]);
        int n;
        scanf("%d",&n);
        sort(a,a+11);
        int b[n],j=0;
        for(i=10;i>=(10-n);i--) 
        {
          b[j]=a[i];
          j++;
        }
        int c=0,d=0;
        for(i=0;i<n;i++) 
        {
          if(b[n-1]==b[i]) c++;
        }
 
        for(i=0;i<11;i++)
        {
          if(b[n-1]==a[i]) d++;
        }
 
        int p=find_ncr(d,c);
        printf("%d\n",p);
      
       
    }
    return 0;
} 
