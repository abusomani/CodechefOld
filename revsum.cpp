   //  revsum   problem 2
#include<iostream>
using namespace std;
int rev(int n)
{
	int rem,rev=0;
	while(n)
	{
		rem=n%10;
		rev=rev*10+rem;
		n/=10;
	}
	return rev;
}
int main()
{
	int t,a,b,sum;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		sum=rev(a)+rev(b);
		cout<<rev(sum)<<endl;
	}
}
