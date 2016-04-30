
// @BEGIN OF SOURCE CODE

#include<bits/stdc++.h>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin,(c).end()
#define tr(c,i) for(typeof((c).begin());i!=(c).end();++i)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x))!=(c).end()
#define ll long long
#define MOD 1000000007
#define siz 100005
#define unsigned32 4294967295


int P[10003],k1,prime[10003];
void sieve()
{
	P[k1++]=2;
	for(int i=3;i*i<1000003;i+=2) // i will go upto 1000
		{
			if(!prime[i])
				{
					P[k1++]=i;
					for(int j=i*i;j<1000003;j++)
						prime[j]=1;
				}
		}
	for(int i=1001;i<1000003;i+=2) //hence we continue the loop from 1001
		{
			if(!prime[i])
				P[k1++]=i;
		}
}


ll int subset[10010][10010];

bool SubsetSumCheck(int w[],int l,int r,int w1)
{
    for (int i=l;i<=r;++i)
      subset[0][i] = true;
    for (int i =1;i<=w1;++i)
      subset[i][0] = false;
     for (int i =1;i<=w1;++i)
     {
       for (int j =l;j<=r;j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i>=w[j-1])
           subset[i][j] = subset[i][j]||subset[i - w[j-1]][j-1];
       }
     }
     return subset[w1][r];
}



ll fct[siz];
int t,n,k;
int p[siz], q[siz], has[siz];

ll power(int k, int l)
{
    
    if (l == 1)
    {
        return k;
    }
    if (l == 2)
    {
        return (k*k) % MOD;
    }
    int mid = l / 2;
    ll res = power(power(k, mid), 2);
    if (mid * 2 != l)
    {
        res = (res*k)%MOD;
    }
}

int leftright(int i)
{
    int count = 0;
    for (int j = i+1; j < n; j++)
    {
        if (q[j] < q[i])
        {
            count++;
        }
    }
    return count;
}

ll inv(int k)
{
    return power(k, MOD - 2);
}

ll fctorial(int n, int k)
{
    
    ll fctk = fct[k];
    ll fctn = fct[n];
    ll div = power(fct[k], MOD - 2);
    return (fctn*div) % MOD;
}

int main()
{
    int i,t;	
	
    ll n,k;

	int x,count;
	  ll ans = 0;
      ll temp = 0;
      
    fct[0] = 1;
    for (i = 1; i < siz;++i)
    {
        fct[i] = (fct[i - 1] * i) % MOD;
    }
    
	scanf("%d",&t);
    
	while (t--)
    {
        cin >> n >> k;
        for (i = 0; i < n; ++i)
        {
            cin >> p[i];
            has[p[i]] = i; 
        }
        for (i = 0; i < n; ++i)
        {
            cin >> q[i];
        }
        x=0,count=0;
        
        
        for ( i = 0; i < n; ++i)
        {
            if (i - has[q[i]] != 0)
            {
                count++;
                x = x + (i - has[q[i]]);
            }
        }

        if (x != 0)
        {
            printf("-1\n");
        }
        else if (count%k != 0)
        {
            printf("-1\n");
        }
        else
        {
            
            for (i = 0; i <= n-k; ++i)
            {
                temp += (leftright(i)*fct[n - i]) % MOD;
            }
            ans = (temp*inv(fct[k])) % MOD;
            printf("%lld\n",ans);
        }
    }

    return 0;
}


