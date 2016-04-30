#include<stdio.h>
 
int main()
{
	int t;
	long long int a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&a);
		scanf("%lld",&b);
		if(b!=0)
			printf("%lld %lld\n",a/b,a%b);
		else
			printf("0 %lld\n",a);
	}
	return 0;
}
 
