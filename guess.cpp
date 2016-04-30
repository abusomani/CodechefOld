#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)		{	return ( b == 0) ? a : gcd(b , a%b);	}

int main()
{
	int t;
	cin>>t;
	long long N, M, o1, o2, e1, e2, sum, tot, g;
	while(t--)
	{
		cin>>N>>M;
		e1 = N/2;	o1 = N - e1;	
		e2 = M/2;	o2 = M - e2;
		sum = (ll)o1*e2 + o2*e1;
		tot = (ll)N*M;
		g = gcd(sum , tot);
		sum /= g;		tot /= g;
		printf("%lld/%lld\n",sum,tot);	
	}
}
