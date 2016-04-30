#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	long long N,M;
	while(t--)
	{
		cin>>N>>M;
		
		int a[M];
		
		for(int i=0;i<M;i++)
		cin>>a[i];
		
		
		sort(a,a+M);
		
		int start=0,end=M-1;
		int ans=0;
		while(start<end)
			{
				if(a[start]==1)
					{
						a[start]--;
						start++;
						
					}
					
				else
					{
						a[start]--;
					}
						ans++;
						a[end]=a[end]+a[end-1];
						end--;
			}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
