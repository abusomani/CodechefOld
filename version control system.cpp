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
			int n,m,k;
			cin>>n>>m>>k;
			int a[n+1][2],tandi=0,uandu=0;
			for(int i=0;i<n+1;i++)
				{
					for(int j=0;j<2;j++)
						a[i][j]=0;
				}
			int x;
			for(int i=0;i<m;i++)
				{
					cin>>x;
					a[x][0]++;//ignored	
				}
			
			for(int i=0;i<k;i++)
				{
					cin>>x;
					a[x][1]++;//tracked	
				}
			for(int i=1;i<=n;i++)
				{
					if(a[i][0]!=0&&a[i][1]!=0)
					tandi++;
					
					else if(a[i][0]==0&&a[i][1]==0)
						uandu++;
				}
			cout<<tandi<<" "<<uandu<<endl;
		}
	return 0;
}
