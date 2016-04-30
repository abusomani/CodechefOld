#include<stdio.h>
int main()
{
	int i,t;
	long int c1,c2;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%ld %ld",&c1,&c2);
		if(c1>c2)
		
		{
			printf("%d %d",c1,c1+c2);
		}
		else
		{
			printf("%d %d",c2,c1+c2);
		}
	}
}
