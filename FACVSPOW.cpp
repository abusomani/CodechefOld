#include<stdio.h>
#include<math.h>
#define scanint(x)  scanf("%d",&x)
#define p(x)  printf("%ld",x)
typedef unsigned long long ull;
ull fact(int n)
{
	ull res=1;
	for(int i=1;i<=n;i++)
	res=res*i;
	return res;
}
int main()
{
	int t,a;
	scanint(t);
	while(t--)
	{
		scanint(a);
		int n=1;
		while(1)
		{
			if(pow(a,n)<fact(n))
			break;
			else
			n++;
		}
		p(n);
		printf("\n");
	}
}
