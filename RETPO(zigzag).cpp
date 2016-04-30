#include<stdio.h>
int main()
{
	int t,count;
	long x,y;
	scanf("%ld", &t);
	while(t--)
	{
		count=0;
		scanf("%ld  %ld", &x, &y);
	    if(x<0)  x=-x;
	    if(y<0)  y=-y;
		if(y==0)
		{
		    if(x%2==0)
			count+=2*x;
			else
			count+=2*x+1; 
	    }
	    else
	    {
		if(x>=y)
		{
			count+=2*y;
			x=x-y;
			if(x%2==1)
			count+=2*x+1;
			else
			count+=2*x;
		}
		else
		{
			count+=2*x;
			y=y-x;
			if(y%2==1)
			count+=2*y-1;
			else
			count+=2*y;
		}
	    }
		printf("%ld\n",count);
	}
}
