#include <bits/stdc++.h>
#define M 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main()
{
	ll N , K;
	ll a0 , d , lasta0 , lastd , unmatch;
	ll a[M];
	
	scanf("%lld %lld",&N , &K);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld",&a[i]);
	}

	lasta0 = INT_MAX;
	lastd  = INT_MAX;
	for(int i = 0 ; i<K+2 ; i++)
	{
		for(int j = 0 ; j<i ; j++)
		{
			a0 = a[j];
			d  = (a[i] - a[j]) / (i-j);
		//	cout<<i<<"  "<<j<<"  "<<a0<<"  "<<d<<endl;
			if((a[i] - a[j]) % (j-i) != 0)
				continue;

			a0 = a[j] - j*d;
		//	cout<<i<<"  "<<j<<"  "<<a0<<"  "<<d;
			unmatch = 0;
			for(int k = 0 ; k<N ; k++)
			{
				if(a[k] != a0)
					unmatch++;
				if(unmatch > K)
					break;
				a0 = a0 + d;
			}
		//	cout<<" ->  "<<unmatch<<endl;
			a0 = a[j] - j*d;
			if(unmatch <= K)
			{
				if(a0 < lasta0)
				{
					lasta0 = a0;
					lastd  = d;
				}
				else if(a0 == lasta0)
				{
					if(d < lastd)
					{
						lasta0 = a0;
						lastd  = d;
					}
				}
			}
		}
	}

	a0 = lasta0;	d = lastd;
	for (int i = 0; i < N; ++i)
	{
		printf("%lld ", a0);
		a0 = a0 + d;
	}
	printf("\n");
}
