#include<bits/stdc++.h>
using namespace std;
int main()
{int found=0,count=0;
	long long n,k;
	cin>>n>>k;
	long long x,b[n];
	for(int i=0;i<n;i++)
		cin>>b[i];
	sort(b,b+n);
	for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
				{
					x=b[i]+b[j];
					
					if(x==k)
						{
							found=1;
						}
				}
		}
	if(found)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
return 0;
}
