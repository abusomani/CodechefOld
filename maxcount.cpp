#include<iostream>
using namespace std;
int main()
{
	int t,count=0,precount=0,i,j,temp,n,value;
	cin>>t;
	while(t--)
	{
		precount=0;
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++)
		{
			count=0;
			temp=a[i];
			for(j=0;j<n;j++)
			{
				if(a[j]==temp)
				count++;
			}
			if(count==precount  &&  temp<value)
			value=temp;
			 if(count>precount)
			{  precount=count;  count=0;  value=temp;   }
		}
		cout<<value<<" "<<precount<<endl;
	}
}
