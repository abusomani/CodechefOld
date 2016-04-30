#include<bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
		return 0;
		
	return 1;
}
int	leastprimepartition(int n)
{ int count=0,temp=n;
	while(temp%2==0)
		{
			count++;
			temp/=2;
		}
	
	for(int i=3;i*i<=n;)
		{while(temp%i==0)
			{count++;
			temp/=i;
			}
			/*if(temp!=1)
			count+=isprime(temp);*/
		i+=2;
		}
		if(temp!=1)
		count+=isprime(temp);
	return count;
}
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		
			if(n>2&&(n%2==0))
				cout<<"2\n";
			else
				{
					if(isprime(n))
					cout<<"1\n";
					else
					cout<<leastprimepartition(n)<<endl;
					
				}
				
	}
	
	return 0;
}
