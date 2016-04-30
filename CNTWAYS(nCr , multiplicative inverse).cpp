#include <bits/stdc++.h>
#define MAX 800010
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll fact[MAX] , ifact[MAX];

ll power(ll base , ll exp)
{
	base = base%exp;
	ll res = 1LL;
	while(exp > 1)
	{
		if(exp&1)
			res = (res*base)%MOD;
		exp >>= 1;
		base = (base*base)%MOD;
	}
	return res;
}

ll invMod(ll a , ll b)				// Multiplictive Inverse  faster than fermet theorem
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) 
	{
		return 1;
	}
	while (a > 1) 
	{
		q = a / b;
		t = b; 
		b = a % b; 
		a = t;
		t = x0; 
		x0 = x1 - q * x0; 
		x1 = t;
	}
	if (x1 < 0)
	{
		x1 += b0;
	}
	return x1;
}

ll prefact()
{
	fact[0] = ifact[0] = 1;
	for (int i = 1; i < MAX; ++i)
	{
		fact[i] = fact[i-1]*i;
		if(fact[i] > MOD)
			fact[i] %= MOD;
		ifact[i] = invMod(fact[i] , MOD);
	}
}

ll nCr(ll n , ll r)
{
	return ((fact[n] * ifact[n-r]) %MOD * ifact[r]) % MOD;
}

ll ways(ll N , ll M)
{
	return nCr(N+M , N); 
}

int main()
{
	int Cases;
	int N , M , A , B;
	prefact();
	scanf("%d" , &Cases);
	while(Cases--)
	{
		scanf("%d %d %d %d" , &N , &M , &A , &B);
		ll res = 0LL;
		for (int i = A; i <= N; ++i)
		{
			res += (ways(i , M-B) * ways(N-i , B-1));
			if(res > MOD)
				res %= MOD;
		}
		printf("%lld\n", res);
	}	
}
