#include<iostream>
#include<cmath>
using namespace std;
bool isprime(long a)
{
	if(a==1)
	return 0;
	if(a==2)
	return 1;
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
		return 0;	
	}
	return 1;
}
bool palindrome(long a)
{
	long b=0,c=a;
	while(a>0)
	{
		
		b=b*10+a%10;
		a=a/10;
	}
	if(b==c)
	return 1;
	return 0;
}
int main()
{ios_base::sync_with_stdio(false);
	long a;
	cin>>a;
	for(int i=a;;i++)
	{
		if(palindrome(i)&&isprime(i))
		{
			cout<<i;
			break;
		
		}
	};
}
