#include <bits/stdc++.h>
#define M 10005
#define MOD 1000000007
using namespace std;
typedef long long ll;
 
ll mulmod(ll A,ll B,ll mod)						// (a*b) %c
{
	long double ans;
	ll C;
	A = A%mod;   B = B%mod;
	ans = (long double)A*B;
	A = A*B;
	C = (ll)(ans/mod);
	A = A - C*mod;
	A = A%mod;
	if(A<0)		 A += mod;
	return A;
}
 
ll f(ll x, ll n) 
{
	double y = pow(x,(double)1/n);
	ll lo = y;
	ll hi = y+0.5;
	
	if(hi == lo) return lo;
	
	if(pow(hi,n) <= x) return hi;
	else return lo;
}
 
int main()
{
	freopen("E://ii.txt" , "r" , stdin);
	int t , N , Q;
	ll x , ans , K;
	
	/*
	x = 1000000000000000000;
	for(int i = 1 ; 1 ; i++)			//	x atmost takes 60 step to lower down to 1
	{
		K = f(x,i);
		if(K == 1)
			break;
		cout<<i<<" : "<<K<<endl;
	}
	*/
	
	ll a[M] , sum[M];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&N,&Q);
		for(int i = 0 ; i<N ; i++)
			scanf("%lld",&a[i]);
		
		sum[N-1] = a[N-1];
		for(int i = N-2 ; i>=0 ; i--)
		{
			sum[i] = sum[i+1] + a[i];
			
			if(sum[i] < 0)
				sum[i] = (sum[i]%MOD + MOD) % MOD;
			else if(sum[i] >= MOD)
				sum[i] %= MOD;
		}
			
			
		while(Q--)
		{
			scanf("%lld",&x);	
			ans = 0;
			int i;
			
			ans = mulmod(x,a[0],MOD);
			
			for(i = 2 ; i<=N ; i++)
			{
				K = f(x,i);
				if(K <= 1)
					break;
				ans = (ans + mulmod(K,a[i-1],MOD));
				
				if(ans < 0)
					ans = (ans%MOD + MOD)%MOD;
				else if(ans > MOD)
					ans %= MOD;
			}
			if(i<N)
				ans = (ans + sum[i]) % MOD;
				
			if(ans > MOD)
				ans %= MOD;	
			else if(ans < 0)
				ans = (ans%MOD + MOD)%MOD;
				
			printf("%lld ",ans%MOD);
		}
		
		printf("\n");
	}	
} 

