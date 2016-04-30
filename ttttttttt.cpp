#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)	
		{
			int n,k;
			cin>>n>>k;
			char a[n],b[n],one='1',zero='0';
			cin>>a;
			
			long long sum=0,len=1,j=0,value,count=0,start;
			
			if(k==1)
				{start=a[0];
					if(start=='1')
					{
						for(int i=0;i<n;i++)
							{
							if(i%2==0)
								b[i]=one;
							else
								b[i]=zero;
							if(b[i]!=a[i]) sum++;	
							}	
					}
					else if(start=='0')
					{
						for(int i=0;i<n;i++)
							{
							if(i%2==0)
								b[i]=zero;
							else
								b[i]=one;
							if(b[i]!=a[i]) sum++;	
							}	
					}
				cout<<sum<<endl;
				for(int i=0;i<n;i++)
				cout<<b[i];
				cout<<endl;
					
				}
					
				
			else
			{
			 while(j<=n-1)
					{start=j;
					value=a[j];
					while(a[j]==a[j+1]&&j<=n-1)
						{
							len++;
							j++;
						}
					sum+=len/(k+1);
					
					 if(len%(k+1)!=0)
						{
							if(value=='1')
								{int index=start+k;
									while(index<=j)
									{
										a[index]='0';
										index+=k+1;
									}
								}
							else
								{
								 int index=start+k;
									while(index<=j)
									{
										a[index]='1';
										index+=k+1;
									}	
								}
						}
					else
						{
							if(value=='1')
								{int index=start+k/2;
									while(index<=j)
									{
										a[index]='0';
										index+=k+1;
									}
								}
							else
								{
								 int index=start+k/2;
									while(index<=j)
									{
										a[index]='1';
										index+=k+1;
									}	
								}
						}
					len=1;  
					j++;
					}
				cout<<sum<<endl;
				for(int i=0;i<n;i++)
				cout<<a[i];
				cout<<endl;
			 	
			}
				
		}
	return 0;
}
