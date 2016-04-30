#include <bits/stdc++.h>
#define M 5000005
#define MOD 1000000007
using namespace std;
typedef long long ll;

bool mark[M];
ll ans[M];
vector<int> prime;

void sieve(int N)
{
	memset(mark , false , sizeof(mark));
	prime.push_back(1);
	for (int i = 2; i < N; ++i)
	{
		if(!mark[i])
		{
			prime.push_back(i);
			for (int j = i; j < N; j += i)
				mark[j] = true;
		}
	}
}

int main()
{
	sieve(M);

	ans[0] = ans[1] = 1;
	ans[2] = 2;
	ans[3] = 6;
	
	for(int i = 3 ; i<prime.size() ; i++)
	{
		for(int j = prime[i-1] ; j < prime[i] ; j++)
		{
			ans[j] = i;
		}
	}

	for(int i = 1 ; i<M ; i++)
	{
		ans[i] = (ans[i-1]*ans[i]);
		if(ans[i] > MOD)
			ans[i] %= MOD;
	}
	
	ans[4999999] = 689423663;
	ans[5000000] = 796804871;
	int Cases , N;
	scanf("%d" , &Cases);
	while(Cases--)
	{
		scanf("%d" , &N);
		printf("%lld\n" , ans[N]);
	}	
}
