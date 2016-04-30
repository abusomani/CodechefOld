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
#define tr(c,i) for(typeof((c).begin());i!=(c).end();i++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x))!=(c).end()
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295



int P[10003],k,prime[10003];
void sieve()
{
	P[k++]=2;
	for(int i=3;i*i<1000003;i+=2) // i will go upto 1000
		{
			if(!prime[i])
				{
					P[k++]=i;
					for(int j=i*i;j<1000003;j++)
						prime[j]=1;
				}
		}
	for(int i=1001;i<1000003;i+=2) //hence we continue the loop from 1001
		{
			if(!prime[i])
				P[k++]=i;
		}
}

ll p[300001], a[300001], h[300001], ans[300001];

int main()
{ios_base::sync_with_stdio(false);


    ll n;
    cin >> n;
    int i,j,tmp;
    
    
    for (i = 0; i < n; i++)
        cin >> p[i];
    
	for ( i = 0; i < n; i++)
        cin >> a[i];
    
	for ( i = 0; i < n; i++)
        cin >> h[i];

    ans[0] = 0;
    
	for ( i = 1; i < n; i++)
    {
        bool compute = false;
        int min;
        for ( j = 0; j < i; j++)
        {
            if (p[i] > p[j] && ans[j]!=-1)
            {
                
                 tmp = h[i] - h[j];
                tmp = tmp*tmp + a[j] + ans[j];
                if (compute)
                {
                    if (min > tmp)
                    {
                        min = tmp;
                    }
                }
                else
                {
                    min = tmp;
                    compute = true;
                }
            }
        }
        if (compute)
        {
            ans[i] = min;
        }
        else
        {
            ans[i] = -1;
        }
    }
    cout << ans[n - 1] << endl;
    return 0;
}


