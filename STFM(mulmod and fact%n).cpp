#include<bits/stdc++.h>
#define lim 100000000
#define L 7200
#define MAX 100005
using namespace std;
typedef long long ll;
ll fact_mod(ll n,int m)
{
	if(n>m)		return 0;			//		if n> mod_value  then fact%m will be 0
	ll fact = 1LL;
	for(int i=2;i<=n;i++)
	{
		fact = (fact*i)%m;
		if(fact == 0)
			return 0;
	}
	return fact;
}
int mulmod(ll a, ll b, int mod)					
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
ll fterm(ll a,int m)
{
	int M = 2*m;
	if(a<lim)	
	{	a = (((a*a)%M)*(a+1))%M;	}
	else
    	a = mulmod(mulmod(a,a,M),a+1,M);
    a /= 2;
    return a%m;
}
ll arr[MAX];
int store[L+2];

int main()
{
	int n,m;
	ll sum,value;
	scanf("%d %d",&n,&m);
	sum = 0;
	bool flag = 1;
	memset(&store,0,sizeof(store));
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(arr[i] > L)
			flag = 0;
		
	}
	if(flag)
	{
		for(int i=0;i<n;i++)
		{
			if(store[arr[i]] != 0)
				value = store[arr[i]];
			else
				value =  (fterm(arr[i],m) + fact_mod(arr[i]+1,m) - 1) % m,
				store[arr[i]] = value;
				
			sum = (sum+value)%m;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			sum = (sum + fterm(arr[i],m) + fact_mod(arr[i]+1,m) - 1) % m;
			if(sum<0)
				sum += m;
		}
	}
	printf("%d\n",sum%m);
}
