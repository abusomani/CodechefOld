#include <bits/stdc++.h>
#define M 100005
#define L 100005
#define LIM 320
#define sz 66
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
vector<int> primes;

struct fact
{
	ll power[sz];
	ll extra;
	fact()
	{
		for(int i = 0 ; i<sz ; i++)
			power[i] = 0;
		extra = 0;
	}
};

fact f[M];
int mark[L];
int pos[L];

ll pow(int base, ll exponent, int modulus)
{
    int result = 1;
    base = base % modulus;
    while (exponent > 0)
    {
        if (exponent%2 == 1)
           result = (ll)(result * base)% modulus;
        exponent = exponent >> 1;
        base = (ll)(base * base) % modulus;
    }
    return result;
}

void markmultiples(int n , int k)
{
	for(int i = k ; i<n ; i+=k)
		mark[i] = k;
}
void sieve(int n)
{
	memset(mark , false , sizeof(mark));
	for(int i = 2 ; i<n ; i++)
	{
		if(!mark[i])
		{
			primes.push_back(i);
			markmultiples(n , i);
		}
	}
}

void factor(int n)
{
	int keep = n;
	while(n>1)
	{
		if(mark[n] > LIM)
			f[keep].extra += keep*mark[n];	
		else
			f[keep].power[pos[mark[n]]] += keep;
		n /= mark[n];
	}
}

int main()
{
	freopen("E://pp.txt" , "r" , stdin);
	sieve(L);
	int prime[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37 , 41 , 43 , 47 , 53 , 59 , 61 , 67 , 71 , 73 , 79 , 83 , 89 , 97 , 101 , 103 , 107 , 109 , 113 , 127 , 131 , 137 , 139 , 149 , 151 , 157 , 163 , 167 , 173 , 179 , 181 , 191 , 193 , 197 , 199 , 211 , 223 , 227 , 229 , 233 , 239 , 241 , 251 , 257 , 263 , 269 , 271 , 277 , 281 , 283 , 293 , 307 , 311 , 313 , 317};
	for(int i = 0 ; i<sz ; i++)
	{
		pos[prime[i]] = i;
	}
	
	for(int i = 2 ; i<M ; i++)
	{
		factor(i);
	}
	for(int i = 3 ; i<M ; i++)
	{
		for(int j = 0 ; j<sz ; j++)
		{
			f[i].power[j] += f[i-1].power[j];
		}
	}
	
	int Cases;
	scanf("%d",&Cases);
	int N , r , mod , q;
	ll ans;
	while(Cases--)
	{
		scanf("%d %d %d",&N , &mod , &q);
		if(mod == 1)
		{
			while(q--)
			{
				scanf("%d" ,&r);
				printf("0\n");
			}
		}
		else
		{
			while(q--)
			{
				scanf("%d" ,&r);
				ans = 1LL;
				for(int i = 0 ; i<sz ; i++)
				{
					ans = (ans * pow(prime[i] , f[N].power[i] - f[r].power[i] - f[N-r].power[i] , mod)) %mod;
				}
				cout<<ans<<endl;
				for(int i = sz ; primes[i] < N ; i++)
				{
					ans = (ans * pow(prime[i] , prime[i] , mod)) %mod;
					cout<<i<<"  "<<primes[i]<<"   "<<ans<<endl;
				}
				printf("%lld\n" , ans);
			}
		}
	}	
}
