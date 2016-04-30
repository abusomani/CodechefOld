#include<bits/stdc++.h>
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
			int b;
			cin>>b;
			int ans=b/2;
			ans=ans*(ans-1)/2;
			cout<<ans<<endl;
		}
	return 0;
}

