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


/*
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
	int l=((struct T*)p1)->(data);
	int r=((struct T*)p2)->(data);
	 return (l-r);
}
*/

int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		int M,x,y;
		cin>>M>>x>>y;
		int test= x*y;
		int a[101]={0};
		int X;
		for(int i=0;i<M;i++)
			{
				cin>>X;
				a[X]=1;
				for(int i=1;i<=test;i++)
					{
						if(X+i>=101)
							break;
						a[X+i]=1;
					}
				for(int i=1;i<=test;i++)
					{	if(X-i<1)
						break;
						a[X-i]=1;
					}
				
			}
		int count=0;
		
		for(int i=1;i<=100;i++)
			if(a[i]==0)
				count++;
				
			cout<<count<<endl;
	}

	return 0;
}


// @END OF SOURCE CODE
