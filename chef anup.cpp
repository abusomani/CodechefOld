#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{
		 long long n,k,l,c=0,c1=0,c2=0;
		 cin>>n>>k>>l;
		 int a[n];
		 for(int i=0;i<n;i++)
		 	a[i]=1;
		for(int i=2;i<=l;i++)
			{	a[n-1]++;
				if(a[n-1]>k)
					{a[n-1]=1;
					int count=n-2;
					while(true)
						{
							a[count]++;
							if(a[count]>k)
								{
								a[count]=1;
								count--;}
							else
							break;
						}
				
					}
				
			}
		for(int i=0;i<n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}
