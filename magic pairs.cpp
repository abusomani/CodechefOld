#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
	{
		long long n,x;
		cin>>n;
		long long a[n];
		long long count=(n*(n-1))/2;
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		cout<<count<<endl;
		
	}
	return 0;
}
