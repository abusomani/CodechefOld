#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{	int n;
		cin>>n;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
		for(int i=0;i<n;i++)
			{
				cin>>b[i];
			}
		sort(a,a+n);
		sort(b,b+n);
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			int x=a[i],y=b[i];
			sum+=(x*y);
		}
		cout<<sum<<endl;
	}
	return 0;
}