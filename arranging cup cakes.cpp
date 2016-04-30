#include<bits/stdc++.h>
using namespace std;
int checkprime(int n)
	{for(int i=2;i<=sqrt(n);i++)
		{if(n%i==0)
			return i;
		}
	return 0;
		
	}
int main()
	{
	int t;
	cin>>t;
	while(t--)
		{int n;
		cin>>n;
		int x=checkprime(n);
			if(x)
				{cout<<n-1<<endl;
				continue;
				}
			else
				{
				}
		}
	return 0;
	} 
