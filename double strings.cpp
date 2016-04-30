#include<stdio.h>
#include<string.h>
int main()
{
    char s[13];
     int test,l,n;
    scanf("%d",&test);
    while(test--)
 {
     scanf("%s",s);
     l=strlen(s);
 
      if((n=(int)(s[l-1]-48))%2)
     {
         s[l-1]-=1;
         printf("%s\n",s);
     }
     else
     {
         printf("%s\n",s);
     }
 }
    return 0;
} 
