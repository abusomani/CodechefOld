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


int P[100000],k,prime[1000000]={0};
void sieve()
{
	P[k++]=2;
	for(int i=3;i*i<1000000;i+=2)
		{
			if(!prime[i])
				{
					P[k++]=i;
					for(int j=i*i;j<1000000;j++)
						prime[j]=1;
				}
		}
	for(int i=1001;i<1000000;i+=2)
		{
			if(!prime[i])
				P[k++]=i;
		}
}

struct Points
{
	ll y;
	ll index;
	
};
int compare(Points p1,Points p2)
{
	return p1.y>p2.y;
}

int main()
{ios_base::sync_with_stdio(false);

	ll t;
	cin>>t;
	while(t--)
		{
			ll n,m,count=0;
			cin>>n;
			Points p[n+1];
			ll a[n+1];
			while(n--)
				{
					
					cin>>m;
					ll max=-100000000000,x,y;
					for(ll i=0;i<m;i++)
						{
							cin>>x>>y;
							if(y>max)
							max=y;
						}
					
					
					
					p[count].y=max;
					p[count].index=count;
					count++;
				
				}
				
		
			
			sort(p,p+count,compare);
			
	
			for(ll i=0;i<count;i++)
				{
					a[p[i].index]=count-i-1;
				}
			for(ll i=0;i<count-1;i++)
				cout<<a[i]<<" ";
			cout<<a[count-1]<<endl;
		}
	return 0;
}

