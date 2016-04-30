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
			long long a[n],val=k;;
			long long ans=0;
			a[0]=val/val;
			for(int i=1;i<n;i++)
				{
					a[i]=(a[i-1]*(val+i)/i)%MOD;
					cout<<a[i]<<"  ";
				}
			long long ways=2*(n-1);
			ans+=n;
			for(int i=1;i<n;i++)
				{
					long long x=(ways*a[i])%MOD;
					ans=(ans+x)%MOD;
					ways-=2;
				}
			cout<<ans<<endl;
				
			
		}
	return 0;
}

