#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long sum=0,C,checksum=(n*(n+1))/2;
	while(n--)
		{
		cin>>C;
		sum+=C;
		}
	 if(checksum==sum)
		cout<<"YES\n";
	else
	cout<<"NO\n";

		return 0;
		
}
