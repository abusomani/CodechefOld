#include<bits/stdc++.h>
using namespace std;


int main()
{
	
	int t;
	cin>>t;
	while(t--)
		{
			
			int N;
			cin>>N;
			int a[N][N],coord[N*N+3][2];
			long long ans=0;
			
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
					{
						cin>>a[i][j];
						coord[a[i][j]][0]=i;
						coord[a[i][j]][1]=j;
					}
			}
			
			for(int i=2;i<=N*N;i++)
				ans+=abs(coord[i][0]-coord[i-1][0])+abs(coord[i][1]-coord[i-1][1]);
				
			cout<<ans<<endl;
			
		}
	
	
	
	return 0;
}
