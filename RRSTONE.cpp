#include<stdio.h>
void main()
{
	int n;
	long a[100000];
	long max,min,k,i;
	int flag=0;
	scanf("%d %ld",&n,&k);
	scanf("%ld",&a[0]);
	max=min=a[0];
	if(a[0]<0)   flag=1;
	for(i=1;i<n;i++)
	{
		scanf("%ld",&a[i]);
		if(a[i]>max)
		max=a[i];
		if(a[i]<min)
		min=a[i];
		if(a[i]<0)
		flag=1;
	}
	if(k==0)
	{
		for(i=0;i<n;i++)
	       	printf("%ld ",a[i]);
	       printf("\n");
	}
	else
	{
	if(flag)
	{
		if(k%2==1)
		{
		    for(i=0;i<n;i++)
	        printf("%ld ",max-a[i]);
	        printf("\n");
		}
		else
		{
			for(i=0;i<n;i++)
	        printf("%ld ",a[i]-min);
	         printf("\n");
		}
	}
	else
	{
		if(k%2==1)
		{
			for(i=0;i<n;i++)
	        printf("%ld ",max-a[i]);
	        printf("\n");
		}
		else
		{
			for(i=0;i<n;i++)
	        printf("%ld ",a[i]);
	         printf("\n");
		}
	}
}
}
