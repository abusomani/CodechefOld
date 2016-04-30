#include<bits/stdc++.h>
using namespace std;

int main()
{
for(int i=0;i<10;i++)
	{
		int a[42]={0},x,count=0;
		for(int j=0;j<10;j++)
			{
				cin>>x;
				a[x%42]++;
			}
		for(int k=0;k<42;k++)
			{
				if(a[k]!=0)
				count++;
			}
		cout<<count<<endl;
		
	}	
		
	
	return 0;
}
