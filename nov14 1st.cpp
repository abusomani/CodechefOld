#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{	
	int t;
	char s[100002];	
	int a[257];
	scanf("%d",&t);
	while(t--)
	{
		int count =0;
		memset(&a,0,sizeof(a));
		cin>>s;
		for(int i=0;s[i]!='\0';i++)
			a[(s[i])]++;
		for(int i=0;i<257;i++)
			if(a[i]>0)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
