#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			int a[n],b[n];
			for(int i=0;i<n;i++)
				{
					cin>>a[i];
					b[i]=0;
				}
			for(int i=0;i<n-1;i++)
				{
					if(a[i]!=a[i+1])
						{
							b[i]=1;
							b[i+1]=1;
						}
						
				}
			int count=0;
			for(int i=0;i<n;i++)
				{
					if(b[i]!=0)
					count++;
				}
			cout<<count<<endl;
		}
	return 0;
}
