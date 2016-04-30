#include<bits/stdc++.h>
using namespace std;
int prime[1000003]={0};
void sieve()
{

	for(int i=2;i*i<1000003;i++)
		{
			if(prime[i]==0)
				{
					for(int j=i*i;j<1000003;j+=i)
						prime[j]=1;	
				}	
		}
		
		
	
}

int main()
{
	sieve();
	int T;
	cin>>T;
	while(T--)
		{
			int N;
			cin>>N;
			if(prime[N]==0)
				cout<<"LUCKY NUMBER\n";
			else
				cout<<"Sorry\n";
			
		}
}
