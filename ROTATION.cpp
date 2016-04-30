#include<stdio.h>
#include<iostream>
#include<string.h>
#define sz 100002
using namespace std;
int main()
{
	long n,m,i,k=1;
	long *p, *h, *t;
	char c;
	long a[sz];
	scanf("%ld %ld",&n, &m);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&a[i]);
	}
	h = &a[0];		t = &a[n-1];	 
	p = h ;
	for(i=0;i<m;i++)
	{
		cin>>c;	
		scanf("%ld",&k);
		if(c=='A')	k=n-k;
		if(c=='R')
		{
			k--;
			if(p+k<=t)
			{
				printf("%ld\n",*(p+k));
			}
			else
			{
				k = k-(t-p);
				printf("%ld\n",*(h+k-1));
			}
			
		}
		else
		{
			if(p+k<=t)
			{
				p = p+k;
			}
			else
			{
				k = k-(t-p);
				p = h + k - 1;
			}
		}
		
	}
}
