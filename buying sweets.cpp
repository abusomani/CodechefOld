#include<bits/stdc++.h>
using namespace std;
int main()
	{int t;
	
	cin>>t;
		while(t--)
			{int n,x,i,sum=0;
			cin>>n>>x;
			int a[n];
			for(i=0;i<n;i++)
			{
			cin>>a[i];
			sum+=a[i];
			}
			sort(a,a+i);
			int ans=sum/x;
			if(ans==(sum-a[0])/x)
			cout<<"-1"<<endl;
			else
			cout<<ans<<endl;
			}
		return 0;
	}
