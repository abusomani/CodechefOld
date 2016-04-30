#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			int n,m;
			long long sum=0;
			cin>>n>>m;
			if(n==1&&m==1)
				cout<<"1\n";
			else if(n==1||m==1)
				{
					sum+=2;
					if(n==1)
						{
							sum+=2*(m-2);
						}
					else
						{
							sum+=2*(n-2);
						}
					cout<<sum<<endl;
				}
			else
				{
					sum+=3*4+2*((n-2)+(m-2))*5+(n-2)*(m-2)*8;
					cout<<sum<<endl;
				}
			
				
		}
	return 0;
}
