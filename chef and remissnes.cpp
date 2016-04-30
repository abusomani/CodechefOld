#include<stdio.h>
int main()
{int t;
scanf("%d",&t);
while(t--)
	{int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d\n",(a>b?a:b),(a+b));
	}
return 0;
}
