#include<bits/stdc++.h>
using namespace std;
#define M 100010
#define MAX 0x3fffffff

int min(int i ,int j, int k)
{
	return min(i , min(j,k));
}

int a,b,l,m,dp[2][M];
int call(int i, int j)
{
	if(i<0 || i>l)
		return MAX;
	if(j == 0)
		return a*i;
	if(i == 0)
		return a*j;
	if(dp[i%2][j] == -1)
		return MAX;

	return dp[i%2][j];
}
int main()
{
	int t,i,j;
	int k,k1;
	char str1[M] , str2[M];
//	freopen("E://strr.txt" , "r" , stdin);
//	freopen("E://strw.txt" , "w" , stdout);
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %s" ,str1 , str2);
		scanf("%d %d %d" , &a , &b , &k);
		
		l = strlen(str1);     
		m = strlen(str2);
		
		if(strcmp(str1 , str2) == 0)	{	printf("0\n");							continue;	 }	

		if(a == 0) 		{	printf("0\n");											continue;	 }
		if(b == 0)		{	printf("%d\n" , abs((l-m))*a);							continue;	 }
	    
		memset(&dp , -1 , sizeof(dp));
	
		k1 = k;
		for(i = 1 ; i<=l ; i++)
		{
			for(j = max(i-k1 , 1) ; j<=min(i+k1 , m) ; j++)
			{
				if(str1[i-1] == str2[j-1])
					dp[i%2][j] = call(i-1,j-1);
				else
					dp[i%2][j] = min(call(i-1,j) + a , call(i,j-1) + a , call(i-1,j-1) + b);  
			}
		}

		if(dp[l%2][m] <= k)
			printf("%d\n",dp[l%2][m]);
		else 
			printf("-1\n");
	}	
}
