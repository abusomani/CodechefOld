#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		{
			int n,k;
			cin>>n>>k;
			int a[n];
			long long ans=0;
			for(int i=0;i<n;i++)
				{
					cin>>a[i];
					if(a[i]<k)
						{
							ans+=k-a[i];
						}
					else
					{
						int m=a[i]/k,minimum;
						minimum=min(abs((m+1)*k-a[i]),abs((m*k)-a[i]));
						ans+=minimum;
					}
				}
			cout<<ans<<endl;
			
		}
	return 0;
}

