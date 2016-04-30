#include <stdio.h>
#include <math.h>
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long int ull;

ll m;
ll p4(ll s)
{
	ll y = s%30 , sM = s%m ,c2=2 , c3=3,c90=90,c6=6;
	ll t = ((s-y)/30)%m;
	ll last = ( c3*sM*sM + c3*sM -1 )%m;
	ll last_two = ((c2*sM + 1) * last )%m;
	return (t*(sM+1)*last_two  + t*y*last_two + c2*t*y*(y+1)*last + y*(y+1)*(c2*y+1)*(c90*t*t + c6*t*y + c3*t) + (y*(y+1)*(c2*y+1)*(c3*y*y+c3*y-1))/30  )%m;
}

int main()
{
	int t;
	ll n , i , j , sum;
	scanf("%d" , &t);
	while(t--)
	{
		scanf("%lld %lld" , &n , &m);
		sum = 0;
		ll srt = sqrt(n),x,y,z;
		for(ll i = 1 ; i<=srt ; i++)
		{
			x= i;
			sum = (sum + ((i*i*i)%m)*((i*(n/i))%m))%m;
		}
		
		for(ll i = (n/srt) ; i>1 ; i--)
		{
			x = n/i;
			y = n/(i-1);
			sum = (sum + (i-1)* (p4(y) - p4(x)))%m;
		}
		if(sum < 0)
			sum += m;
		printf("%lld\n",sum);
	}
}
