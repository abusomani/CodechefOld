#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{
		int n,w;
		cin>>n>>w;
		int a[n+1];
		for(int i=1;i<=n;i++)
		cin>>a[i];
		int q;
		cin>>q;
			while(q--)
				{
					int pos,col,count=1,ans=0;
					cin>>pos>>col;
					a[pos]=col;
					for(int i=1;i<=n-w;i++)
						{
							int test=w-1,flag=0;
							while(test--)
								{
									if(a[i+1]!=a[i])
										{
											flag=1;
											break;
										}
								}
							if(!flag)
							ans++;
							
								
						}
					cout<<ans<<endl;
					
				}
		
	}
	return 0;
}
