#include<bits/stdc++.h>
using namespace std;
int isPrime(int n)
{int x=sqrt(n);
	for(int i=2;i<=x;i++)
		{
			if(n%i==0)
				return 0;
				
		}
	return 1;
}
long long sumofdivisors(int n)
{
	int x=sqrt(n);
	long long sum=0;
	for(int i=1;i<=x;i++)
		{
			if(n%i==0)
				{
					if(n/i==i)
						sum+=i;
					else
						sum+=i+n/i;
				}
				
		}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			if(n==1)
			cout<<"1\n";
			else
			{
			
				if(isPrime(n))
					cout<<n+1<<endl;
				else
				{
					cout<<sumofdivisors(n)<<endl;
				}
			}
		}
	return 0;
}
