#include<bits/stdc++.h>
using namespace std;
//92+1=29+1=30 3
long long reverse(long long n)
{
	long long temp=0;
	while(n!=0)
		{
			temp=temp*10+n%10;
			n/=10;
		}
	return temp;
}
int main()
{
	long long t;
	cin>>t;
	while(t--)
		{
			long long a,b,sum;
			cin>>a>>b;
			sum=reverse(a)+reverse(b);
			cout<<reverse(sum)<<endl;
			
		}
	return 0;
}
