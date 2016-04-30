#include<iostream>
using namespace std;
int main()
{
	int n,i,j,start,end,sum=0,flag=0;
	cin>>n;
	int a[n+1];
	for(i=1;i<=n;i++)
	cin>>a[i];
	start=1;
	end=n;
	for(i=1;i<=n;i++)
	{
		l:
		if( a[start]<a[end] || flag==1)
		{
			sum+=a[start]*i;
			start++;
			flag=0;
		}
		else if( a[start]>a[end] || flag==2)
		{
			sum+=a[end]*i;
			end--;
			flag=0;
		}
		else
		{
            for(j=1;j<n/2;j++)
            {
            	if(a[start+j]<a[end-j])
            	{
            		flag=1;
            		goto l;
            	}
            	else
            	{
            		flag=2;
            		goto l;
            	}
            }
		}
	}
	cout<<sum<<endl;
}
