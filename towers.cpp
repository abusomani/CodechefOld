#include<bits/stdc++.h>
using namespace std;
struct tower
{
	int value,count,shorter;
};
int main()
{int t;
cin>>t;
while(t--)
	{
		int n,flag=0;
		cin>>n;
		tower t[n];
		for(int i=0;i<n;i++)
			{
			cin>>t[i].value;
			t[i].count=t[i].shorter=0;
			}
		int max=t[n-1].value;	
		for(int i=n-2;i>=0;i--)
			{
				if(t[i].value>=t[i+1].value)
					{
					if(t[i].value>max)
						{max=t[i].value;
						t[i].count=t[i].shorter=n-i-1;
						}
					else
						{t[i].count=t[i+1].count+1;
						t[i].shorter=t[i+1].shorter+1;
						}
					}
				else
					{
					t[i].count=t[i+1].count+1-t[i+1].shorter;
					max=t[i+1].count;	
					}	
			}	
	for(int i=0;i<n;i++)
		{if(i<n-1)
		cout<<t[i].count<<" ";
		else 
		cout<<t[i].count<<endl;
		}
	}
	return 0;
}
