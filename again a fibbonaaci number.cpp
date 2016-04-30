#include<bits/stdc++.h>
#include<set>
#include<map>
#include<list>
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

/*int compare(const void *p1,const void *p2)
{
	int l=((struct T*)p1)->(data);
	int r=((struct T*)p2)->(data);
	 return (l-r);
}
*/
ll arr[99993];
void init()
{
	arr[0]=0;
	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<99993;i++)
		arr[i]=(arr[i-1]+arr[i-2])%99991;
	
}
ll sumOfSubset(list <ll> l)
{ll sum=0,tingu=0;
	for(list<ll>::iterator it=l.begin();it!=l.end();it++)
		{ll v= *it;
			//cout<<v<<"  ";
				tingu += v;
			//cout<<sum<<endl;
		}
	sum=(sum+ arr[tingu%99991])%99991;
	return sum;
}
void subset(ll arr[],int size,int left,int index,list<ll> &l,ll &ans)
{
	if(left==0)
		{
			ans=(ans+sumOfSubset(l))%99991;
			//cout <<ans<<endl;
			return;
		}
	for(int i=index;i<size;i++)
		{
			l.push_back(arr[i]);
			subset(arr,size,left-1,i+1,l,ans);
			l.pop_back();
		}
}

int main()
{ios_base::sync_with_stdio(false);
init();
int n,k;
cin>>n>>k;
list<ll>lt;
ll a[n];
for(int i=0;i<n;i++)
	cin>>a[i];
ll ans=0;
subset(a,n,k,0,lt,ans);
cout<<ans;

	return 0;
}

