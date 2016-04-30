#include<iostream>
#define MAX 100003
using namespace std;
int main()
{int a[MAX]={0},t;
for(int i=1;i<MAX;i++)
	{if(a[i]==0)
		a[i]=1;
	if(2*i<=MAX)
		{if(a[i]==1)
		a[2*i]=a[i]+1;
		else if(a[i]==2)
		a[2*i]=a[i]-1;
		}
	if(2*i+1<=MAX)
		{if(a[i]==1)
		a[2*i+1]=a[i]+1;
		else if(a[i]==2)
		a[2*i+1]=a[i]-1;
		}
	}
cin>>t; 
char ch[2];int x,y,count=0,ans;                    //1 denotes black and 2 denotes red
while(t--)
	{ans=0;
	cin>>ch[0]>>ch[1]>>x>>y;
	if(ch[1]=='i')
		{count++;
		}
	if(ch[1]=='b')
		{if(count%2==0)
				{
				for(int j=x;j<=y;j++)
					{if(a[j]==1)
					ans++;
					}
				}
		else
			{for(int j=x;j<=y;j++)
					{if(a[j]==2)
					ans++;
					}
			}
		}
	if(ch[1]=='r')
		{if(count%2==0)
				{
				for(int j=x;j<=y;j++)
					{if(a[j]==2)
					ans++;
					}
				}
		else
			{for(int j=x;j<=y;j++)
					{if(a[j]==1)
					ans++;
					}
			}
		}
	cout<<ans<<endl;
	}
return 0;	
}
