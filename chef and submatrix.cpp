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


/*int P[100000],k,prime[1000000]={0};
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

int compare(const void *p1,const void *p2)
{
	int l=((struct T*)p1)->(data);
	int r=((struct T*)p2)->(data);
	 return (l-r);
}
*/
int kadane(ll *arr,int n)
{
	int sum=0,maxSum=INT_MIN;
	
	
	int local_start=0;
	
	for(int i=0;i<n;i++)
		{
			sum^=arr[i];
			if(sum>maxSum)
				{
					maxSum=sum;
					//*start=local_start;
					//*finish=i;
				}
			
		}
		for(int i=1;i<n;i++)
			{
				if(arr[i]>maxSum)
					maxSum=arr[i];
			}
		return maxSum;
		
}

int main()
{ios_base::sync_with_stdio(false);

int t;
cin>>t;
while(t--)
	{
		
		int n;
		cin>>n;
		int a[n][n];
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cin>>a[i][j];
			}
			
	ll maxSum=INT_MIN;
	ll temp[n],sum=0;
	
	for(int i=0;i<n;i++)
		{
			memset(temp,0,sizeof(temp));
			for(int j=0;j<n;j++)
				{
					for(int k=0;k<n;k++)
						temp[k]^=a[k][j];
						
					sum=kadane(temp,n);
					if(sum>maxSum)
						maxSum=sum;
				}
				
		}
	cout<<maxSum<<endl;
	}
	return 0;
}


// @END OF SOURCE CODE
