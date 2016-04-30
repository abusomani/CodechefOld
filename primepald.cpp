#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0)  return 0;  
	return 1;
}
bool pald(int n)
{
	int sum=0,rem,k;
	k=n;
	while(n>0)
	{
		rem=n%10;
		sum=sum*10+rem;
	}
	if(sum==k) return 1;
	else return 0;
}
int main()
{
	int i;
	for(i=2;i<10000;i++)
	{
		if(prime(i)||pald(i))
		cout<<i<<endl;
	}
}
