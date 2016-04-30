//      template by Utkarsh trivedi
//      problem id-                       Based on-
/*
Bottom up approach   much  fast
 
#include <cstdio>
const int N = 2048;
int n, m[N][N], v[N];
int max(int a, int b){ return a > b ? a : b; }
int main(void){
    while(scanf("%d", &n) == 1){
        for(int i = 0; i < n; ++i) scanf("%d", v + i), m[i][i] = v[i] * n;
        for(int a = n - 1, L = 1; L < n; --a, ++L)
            for(int s = 0, e = s + L; e < n; ++s, ++e)
                m[s][e] = max(v[s]*a + m[s+1][e], v[e]*a + m[s][e-1]);
        printf("%d\n", m[0][n-1]);
    }
    return 0;
}
*/



#include<stdio.h>
#include<string.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
typedef unsigned long long ull;
int max(int a,int b)
{
	return (a>=b)?a:b;
}
int a[200],dp[200][200]={0};
int n;

//memset(&dp,-1,200*200*sizeof(int));

int solve(int i,int j,int k)
{
	if(i>n-1 || j<0 )     return 0;
	if (i==j)  return a[i]*k; 
	
	if(dp[i][j]!=0)    return dp[i][j];
		dp[i][j]=max(a[j]*k+solve(i,j-1,k+1),a[i]*k+solve(i+1,j,k+1));
	return dp[i][j];
}
int main()
{

	int i,j;
	s(n);
	for(i=0;i<n;i++)
		s(a[i]);
	p(solve(0,n-1,1));
}
