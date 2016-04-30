#include<bits/stdc++.h>
using namespace std;
int isPalin(long long n)
{
	long long temp=0,x=n;
	while(x!=0)
		{
			temp=temp*10+x%10;
			x/=10;
		}
	if(n==temp)
	return 1;
	else
	return 0;
}
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
	int t;
	cin>>t;
	while(t--)
		{
			long long a,palin,count=0;
			cin>>a;
			palin=a+reverse(a);
			count++;
			while(true)
				{
					palin+=reverse(palin);
					count++;
					if(isPalin(palin))
						{
							cout<<count<<" "<<palin<<endl;
							break;
						}
				}
			
			
		}
		
	
	return 0;
}
