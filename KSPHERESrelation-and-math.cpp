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
#define mmm 100005
#define unsigned32 4294967295

int P[1000003],k,prime[1000003]={0};
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
int compare(const void *p1,const void *p2)
{
	int l;//=((struct T*)p1)->(data);
	int r;//=((struct T*)p2)->(data);
	 return (l-r);
}


ll ANSWER[2][mmm];

int a[mmm], countLower[mmm], countUpper[mmm];


int main()
{
    ll n, m, c;
    
    vector<int> v;
    
    
	int x;
	
	
	cin>>n>>m>>c;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        countUpper[a[i]]++;
    }   

    for (int i= 0;i< m;i++)
    {
        cin>>x;
        countLower[x]++;
    }

	set<int> st(a, a + n);
	ll K;
	for (set<int>::iterator p=st.begin();p != st.end();p++)
	{
        K = ((ll)countUpper[*p] * countLower[*p]) % MOD;
        if(K != 0)
            v.push_back(K);
    }
    

    ll sum = v[0];

    int final = 0;
    for (int j=1;j<v.size();j++)
    {
        ANSWER[0][j] = (v[j]*sum)% MOD;
        final = (final+ANSWER[0][j])% MOD;
        sum = (sum+v[j])% MOD;
    }

	printf("%d ",final);
    for (int i=1;i<c;i++)
    {
    	
		sum = ANSWER[1-i%2][i];
		
		final= 0;		
		
        for (int j=i+1;j<v.size();j++)
        {
            ANSWER[i%2][j] = (v[j]*sum)% MOD;
            final = (final+ANSWER[i%2][j])% MOD;
            sum = (sum+ANSWER[1-i%2][j])% MOD;
        }
        printf("%d ",final);
    }
    printf("\n");
}

//END OF SOURCE CODE
