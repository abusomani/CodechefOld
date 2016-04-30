/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod
typedef long long int LL;
using namespace std;

char prime[1000000]={0};
int a[11];
int P[100000],k;

void sieve()
{
	
	P[k++]=2;

	for(int i=3;i*i<1000000;i+=2)
	{
		if(!prime[i])
		{
			P[k++]=i;
			for(int j=i*i;j<1000000;j+=i+i)
				prime[j] = 1;
		}
	}

	for(int i=1001;i<1000000;i+=2)
		if(!prime[i])
			P[k++]=i;
}
int main()
{

	sieve();
	int t,n;
	map<int,int> m;
	scanf("%d",&t);
	while(t--)
	{
		m.clear();
		scanf("%d",&n);

		REP(i,n)
		{
			scanf("%d",&a[i]);
			assert(a[i]>=2 && a[i]<=10);
		}

		REP(i,n)
		{
			REP(j,k)
			{
				while(a[i]>1 && a[i]%P[j]==0) 
				{
					a[i]/=P[j];
					if(m.find(P[j])!=m.end())
						m[P[j]]++;
					else
						m.insert(MP(P[j],1));
				}
			}
			if(a[i]!=1)
			{
				if(m.find(a[i])!=m.end())
					m[a[i]]++;
				else
					m.insert(MP(a[i],1));
			}
		}

		map<int,int>::iterator it;
		LL ans=1;
		for(it=m.begin();it!=m.end();++it)
			ans*=((*it).second+1LL);
		printf("%lld\n",ans);
	}

	return 0;



}
