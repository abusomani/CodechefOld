#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int n,x,c,a[20],count=0,flag=0;
	cin>>n>>c;
	if(n==0)
	cout<<"No"<<endl;
	else
	{
	for(int i=0;i<n;i++)
		{cin>>x;
			if(x<=c)
			a[count++]=x;
		}
	sort(a,a+count);
	for(int i=count-1;i>=0;i--)
		{if(a[i]<=c)
			c-=a[i];
			if(c==0)
				flag=1;
		}
	if(flag)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	}
	}
return 0;
}
