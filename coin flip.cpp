#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
scanf("%d",&t);
while(t--)
	{int n,g,i,q;
	scanf("%d",&g);
	while(g--)
	{scanf("%d%d%d",&i,&n,&q);
	if(i!=q)
		printf("%d\n",(n+1)/2);
	else
		printf("%d\n",n/2);
	}
	}
return 0;
}
