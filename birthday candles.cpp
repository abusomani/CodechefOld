#include<iostream>
#include<algorithm>
using namespace std;

struct candle
{int data;
int value;
};

int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{candle c[10];
	for(int i=0;i<10;i++)
		{c[i].data=i;
		cin>>c[i].value;
		}
	for(int i=0;i<10;i++)
		for(int j=0;j<9;j++)
			{if(c[j].value>=c[j+1].value)
				{if(c[j].value==c[j+1].value)
					{if(c[j].data>c[j+1].data)
						{int x=c[j].data;
						c[j].data=c[j+1].data;
						c[j+1].data=x;
						}
						
					}
				else
					{int x=c[j].data;
					c[j].data=c[j+1].data;
					c[j+1].data=x;
					x=c[j].value;
					c[j].value=c[j+1].value;
					c[j+1].value=x;
					}
				}
			}
	int y=c[0].value,sum=0;
	if(c[0].data!=0)
	{
	for(int i=0;i<=y;i++)
	sum=sum*10+c[0].data;
	cout<<sum<<endl;
	}
	else
	{if(c[0].value!=c[1].value)
		{
		sum=1;
		for(int i=0;i<=y;i++)
		sum=sum*10;
		cout<<sum<<endl;
		}
		else
		{for(int i=0;i<=c[1].value;i++)
	sum=sum*10+c[1].data;
	cout<<sum<<endl;
		}
	}
	}
return 0;
}
