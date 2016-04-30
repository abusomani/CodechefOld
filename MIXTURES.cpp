#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define M 105
#define MAX 214748364
int result[M][M];
int save[M][M];
int main()
{
	int min;
	int n,i,j,k,r,x,p,y;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>p;
			result[i][i] = p;
	    }
	    memset(&save,0,sizeof(save));
		for(i=0;i<n-1;i++)
		{
			save[i][i+1]=result[i][i]*result[i+1][i+1];
			result[i][i+1]=(result[i][i]+result[i+1][i+1])%100;
	    }
	    k=2;
	    while(k!=n)
	    {
	       for(i=0;i<n-k;i++)
		   {
		   	min=MAX;
		   	x=i;     y=i+k;
		   	for(j=x;j<y;j++)
		   	{
		   	    p = save[x][j] + save[j+1][y] + result[x][j]*result[j+1][y];
		   	    if(p<min)
		   	    {  min=p;   r=j;  }
		   	}
		   	save[x][y]=min;    result[x][y]=(result[x][r]+result[r+1][y])%100;
		   }	
		   k++;
	    }
		 /*for(int i=0;i<n;i++)
	    {
	    	for(int j=0;j<n;j++)
	    		printf("%d  ",save[i][j]);
	    	printf("\n");
	    }*/
	    cout<<save[0][n-1]<<endl;
	}
}
