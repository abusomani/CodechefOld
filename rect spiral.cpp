#include<stdio.h>
int i,r, c,*p;
void spiral(int *a,int m, int n)
{
	if(m==1)
	{
		for(i=0; i<n; i++)
		printf("%d ",*(a+i));
	}
	else if(m==2)
	{
				for(i=0; i<n; i++)
		printf("%d ",*(a+i));
		p=a+c-1;
		for(i=0; i<n; i++)
		printf("%d ",*(p-i-1));
	}
	else if(m==0 || n==0)   printf("");
	else
	{
	for(i=0;i<n;i++)
	printf("%d ",*(a+i));
	p=a+(n-1);
	for(i=1;i<m;i++)
	printf("%d ",*(p+c*i));
	p=p+c*(m-1);
	for(i=1;i<n;i++)
	printf("%d ",*(p-i));
	p=p-(n-1);
	for(i=1;i<m-1;i++)
	printf("%d ",*(p-c*i));
	spiral(a+c+1,m-2,n-2);
	}
}
int main()
{
	int j;
	scanf("%d %d",&r,&c);
	int b[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&b[i][j]);
		
		}
	}
	
	spiral(&b[0][0],r, c);
}