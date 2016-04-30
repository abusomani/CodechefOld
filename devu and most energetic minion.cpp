#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
int main()
{ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				{
					cin>>a[i][j];
				}
		}	
		int cost[n][n];
		cost[n-1][n-1]=a[n-1][n-1];
		
		for(int i=n-2;i>=0;i--)
			{
				cost[i][n-1]=cost[i+1][n-1]^a[i][n-1];
			}
		
		
		for(int i=n-2;i>=0;i--)
			{
				cost[n-1][i]=cost[n-1][i+1]^a[n-1][i];
			}
			
		
			for(int i=n-2;i>=0;i--)
			{
				for(int j=n-2;j>=0;j--)
					{
						cost[i][j]=max(cost[i+1][j]^a[i][j],cost[i][j+1]^a[i][j]);
					}
			}
	/*	for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					cout<<cost[i][j]<<"  ";
					
				cout<<endl;
			}*/
			
		cout<<cost[0][0];
		
	return 0;
}
