#include<iostream>
using namespace std;
int main()
{
	int t,n,m,a;
	cin>>t;
	while(t--)
	{
		int hi = -1 , sum = 0 ;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			hi = max(a,hi);
			sum+=a;
		}
		if( sum + m >= hi*n )
		{
			sum = (sum + m - hi*n);
			if(sum%n==0)
				cout<<"Yes\n";
			else
				cout<<"No\n";	
		}
		else
			cout<<"No\n";
	}
}
