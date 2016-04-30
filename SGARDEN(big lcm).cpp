#include <bits/stdc++.h>
#define M 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll power(ll base , ll exp)
{
	ll res = 1LL;
	while(exp > 0)
	{
		if(exp & 1)
			res = (res * base) % MOD ;
		base = (base * base) % MOD ;
		exp = exp>>1;
	}
	return res;
}

int main()
{	
//    freopen("E://input.txt", "r", stdin);

	int t , maxv , K , N , st , a[M];
	bool visit[M];
	int powr[M];
	ll ans = 1 , step;
	
	cin>>t;
	while(t--)
	{
		cin>>N;
		for(int i = 1 ; i <= N ; i++)
			cin>>a[i];
			
		vector<int> v;	
		memset(&visit , false , sizeof(visit));
		memset(&powr , false , sizeof(powr));
		
		ans = 1;
		
		for(int i = 1 ; i <= N ; i++)
		{
			if(!visit[i])
			{
				st = i;
				K = a[st];
				if(K == st)
					continue;
					
				step = 1;
				while(K != st)
				{
					visit[K] = true;
					K = a[K];
					step++;
				}
				if(step>1)
					v.push_back(step);
			}
		}
		
		for(int i = 0 ; i<v.size() ; i++)			//	now getting lcm of all v[i]'s  ,  for this we are storing max pow of 
		{
			for(int j = 2 ; j*j <= v[i] ; j++)
			{
				st = 0;
				while(v[i] % j == 0)
				{
					v[i] /= j;
					st++;
				}
				powr[j] = max(powr[j] , st);
			}
			if(v[i] != 1)
				powr[v[i]] = max(powr[v[i]] , 1);
		}
		
		for(int i = 2 ; i<M ; i++)
		{
			if(powr[i])
				ans = (ans * power(i,powr[i])) % MOD;
		}
		cout<<ans % MOD<<endl;
		v.clear();
	}
}
