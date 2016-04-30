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

struct Values
{
	string s;
	ll number;
};


int compare(const void *p1,const void *p2)
{
	int l=((struct Values*)p1)->number;
	int r=((struct Values*)p2)->number;
	 return (l-r);
}

int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		Values v[n];
		for(int i=0;i<n;i++)
			{
				cin>>v[i].s>>v[i].number;
			}
		qsort((void *)v,n,sizeof(v[0]),compare);
		//for(int i=0;i<n;i++)
		//	cout<<v[i].number<<" ";
		int count=1,flag=0,pos=-1;
	for(int i=1;i<n;i++)
		{
			if(v[i].number==v[i-1].number)
				{
					count++;	
				}
			else
				{
					if(count==1)
						{
							flag=1;
							pos=i-1;
							//cout<<v[i-1].s<<endl;
							break;
						}
					else
						count=1;
					
				}
		}
	if(flag==0&&pos==-1)
		{
			if(v[n-1].number!=v[n-2].number)
				cout<<v[n-1].s<<endl;
			else
				cout<<"Nobody wins.\n";		
		}
		
	else if(flag==1&&pos!=-1)
		cout<<v[pos].s<<endl;
	}

	return 0;
}

