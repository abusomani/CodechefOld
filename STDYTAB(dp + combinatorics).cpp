#include <bits/stdc++.h>
#define MOD 1000000000
#define L 2005
using namespace std;
typedef long long ll;

int a[L+2][L+2];
int b[L+2];

ll mulmod(ll A,ll B)						
{
	long double ans;
	ll C;
	A = A%MOD;   B = B%MOD;
	ans = (long double)A*B;
	A = A*B;
	C = (ll)(ans/MOD);
	A = A - C*MOD;
	A = A%MOD;
	if(A<0)		 A += MOD;
	return A;
}

int main()
{

	for(int i = 1 ; i<=L ; i++)
	{
		a[1][i] = i; 	a[i][1] = 1; 
	}

	for(int i = 2 ; i<=L ; i++)
	{
		for(int j = 2 ; j<=L ; j++)
		{
			a[i][j] = (a[i-1][j] + a[i][j-1]) % MOD;
		}
	}

	int Cases;
	scanf("%d" ,&Cases);
	int n , m;
	long long Ans;
	while(Cases--)
	{
		scanf("%d %d" , &n,&m);
		if(m == 1)		{	printf("%d\n" , n+1);		continue;	}
		
		swap(n,m);
		for(int j = 0 ; j<=n+1 ; j++)
			b[j] = a[n-1][j];
		
		for(int k = 1 ; k<=m ; k++)
		{
			for(int j = n ; j>=1 ; j--)
			{
				b[j] = (b[j] + b[j+1]) % MOD;	
				if(b[j] > MOD)
					b[j] -= MOD;
			}
			for(int j = 1 ; j<=n+1 ; j++)
			{
				Ans = (ll)b[j]*a[n-1][j];
				if(Ans > MOD)
					Ans = Ans % MOD;
				b[j] = Ans;
			}
		}	
		printf("%d\n" , b[1]);
	}	
}
