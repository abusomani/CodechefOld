#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;
#define sz 1000003
#define M 1000000007
/*
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
*/

int main()
{
	ll t;
	ll num;
	char str[sz];
	sl(t);
	while(t--)
	{
		scanf("%s",str);
		int l=strlen(str);
		if(str[0]=='l')		{	num = 2;	}
		else				{	num = 4;	}
		for(int i=1;i<l;i++)
		{
			if(i%2==1)		
			{
				if(str[i]=='l')		{	num = (2*num - 1)%M;	}
				else				{	num = (2*num + 1)%M;	}
			}
			else
			{
				if(str[i]=='l')		{	num = (2*num)%M;		}
				else				{	num = (2*num +2) %M;	}
			}
		}
		pl(num);
		nl;
	}

}
