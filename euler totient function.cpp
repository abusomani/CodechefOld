#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll  gcd(ll a, ll b)
{
	if(a==0)
	return b;
	else if(b==0)
	return a;
	else
	return gcd(b,a%b);
   
}
ll isPrime(ll n)
{
	
	ll sq=sqrt(n);
	for(int i=2;i<=sq;i++)
		{
			if(n%i==0)
			return 0;
			
		}
	return 1;
}
int pow(int base, int exp,int mod)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base%mod;
        exp >>= 1;
        base *= base;
    }

    return result%mod;
}


ll phi(ll n,ll k,int mod)
{
    if(k==0)
    	{
    		if(isPrime(n))
    		return (n-1)%1000000007;	
		}
		else
			{ll sum=0;
			
			   for (ll i=1; i<=n; i++)
    			{
    		    	if (gcd(n, i) == 1)
    	    		sum+=pow(i,k,1000000007)%mod;	
    	    
    			}
    		return sum;
    
			}
    
 
}
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		ll n,k;
		cin>>n>>k;
		cout<<phi(n,k,1000000007)<<endl;
		
	}
	
	return 0;
}
