#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long nPr(long long n,long long r)
{long long value=1,temp=n;
	if(r==0)
		return 1;
		
	else if(r==1)
		return n;
	else
		{
			while(temp>=n-r+1)
				{
					value=(value*temp)%MOD;
					temp--;
				}
			return value;
		}
}
 int main()
 {
 	int t;
 	cin>>t;
 	while(t--)
 		{
 			long long ans, n,k;
 			cin>>n>>k;
 			 ans=nPr(n,k);
 			cout<<ans<<endl;
 		}
 	return 0;
 }
