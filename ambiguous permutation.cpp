#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n&&n!=0)
		{
			int a[n+1],b[n+1],pos=1,x,flag=0;
			for(int i=1;i<=n;i++)
				{
					cin>>b[i];
					a[b[i]]=pos++;
				}
			for(int i=1;i<=n;i++)
				{
					if(a[i]!=b[i])
						{
							flag=1;
							cout<<"not ambiguous\n";
							break;
						}
				}
		if(!flag)
			cout<<"ambiguous\n";
			
		}
	return 0;
}
