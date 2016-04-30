#include<bits/stdc++.h>
using namespace std;
int min(int x,int y,int z)
{
	if(x<y&&x<z)
		return x;
	else if(y<x&&y<z)
		return y;
	else
		return z;
}
int main()
{ios_base::sync_with_stdio(false);

int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		int a[n],x,y,z;
		cin>>a[0];
		if(n==1)
			cout<<a[0]<<endl;
		else
		{
			for(int i=1;i<n;i++)
			{
				cin>>a[i];
				x=a[i-1]+a[i];
				y=a[i-1]-a[i];
				z=a[i-1]*a[i];
				a[i]=min(x,y,z);
				
			}
		cout<<a[n-1]<<endl;
		
		}
	}
	
	
	return 0;
}
