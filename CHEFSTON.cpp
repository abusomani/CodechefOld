#include<iostream>
#define M 100002
using namespace std;
typedef long long ll;
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	ll t,n,k;
	ll a[M],p[M],maxi;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		for(int i=0;i<n;i++)
		{
			cin>>p[i];
		}
		maxi = 0;
		for(int i=0;i<n;i++)
		{
			if( maxi < ((k/a[i])*p[i]) )
				maxi = ((k/a[i])*p[i]);
		}
		cout<<maxi<<endl;
	}
}
