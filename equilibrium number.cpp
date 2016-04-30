#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{
		int n,x,flag=0;
		cin>>n;
		int a[n];
		cin>>a[0];
		for(int i=1;i<n;i++)
			{cin>>x;
			a[i]=a[i-1]+x;
			}
		for(int i=1;i<n-1;i++)
			{
				if(a[i-1]==(a[n-1]-a[i]))
					{flag=1;
					cout<<a[i]-a[i-1]<<endl;
					break;
					}
			}
		if(!flag)
			cout<<"NO EQUILIBRIUM"<<endl;
		
	}
	return 0;
}
