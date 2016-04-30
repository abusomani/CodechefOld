#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,l=1,m,p;
	cin>>n;
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	    a[i][j]=0;
	}
	i=0;  j=n/2;
	for(k=0;k<n*n;k++)
	{
		a[i][j]=l++;
		m=i;   p=j;
	//	cout<<i<<"  "<<j<<endl;
		i=i-1;   j=j+1;
		if(i<0)
		i=n-1;
		if(j==n)
		j=0;
		if(a[i][j]!=0)
		{
			i=m;  j=p;
			i++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	    cout<<a[i][j]<<" ";
	    cout<<endl;
	}
}
