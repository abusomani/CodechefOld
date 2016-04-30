#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
		{
		long long n,k,sum=0,number;
		cin>>n>>k;
		number=(n-k)/2;
		sum=(k+number-1)*number;
		cout<<sum<<endl;
		}
	return 0;
}
