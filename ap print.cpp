#include<stdio.h>
int main()
{
	long t,r;
	int i;
	scanf("%ld",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%ld",&r);
		printf("Case %d: %.2f\n",i,4*r*r+0.25);
	}
}

