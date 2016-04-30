#include<iostream>
using namespace std;
int main()
{
	int i,j,k=0,n,t;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
        long long a[n];
        for(j=0;j<n;j++)
        a[j]=j+1;
        while(n!=1)
        {
        for(j=0;j<n;j++)
        {
        	if(j%2==1)
        	{
        		a[k++]=a[j];   
        	}
        }
        n=n/2;
        cout<<n<<endl;
        }
        cout<<a[0]<<endl;
	}
}
