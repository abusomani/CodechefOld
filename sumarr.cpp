#include<iostream>
#include<new>
using namespace std;
int main()
{
	int t,flag=1,i,j,p,n,min=-10000,temp,l;
	long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long *a=new long[n];
		long *b=new long[n];
	    for(i=0;i<n;i++)
        cin>>a[i];
	    for(i=0;i<n;i++)
	    cin>>b[i];
	    for(i=0;i<n;i++)
	    {
	    	flag=1;
	    	for(j=i;j<n;j++)
	    	{
	    		l=a[i]+b[j]-k;
			    if(l>=0 &&  flag )  {  min=l;  flag=0;  }
	    		if(l>=0 && l<=min)
	    		   {   min=l;   p=j;   } 
	    	}
	    	if(flag==1)  { cout<<"NO\n";   break;  }
	    	temp=b[i];
	    	b[i]=b[p];
	    	b[p]=temp;
	    }
	    	if(i==n)  cout<<"YES\n";
	    	delete[] a;
	    	delete[] b;
	}
}

