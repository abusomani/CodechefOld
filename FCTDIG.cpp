#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>x;
			long l=x, index;
			if(x==1)
			cout<<"1 ";
			else
			{
				
	        	double sum;
				 for (sum = 0, index = 1; index <= l; index++)
	   	             sum += log10((double) index);
	   	    	sum=ceil(sum);
	   	    	cout<<sum<<" ";
	   	    }
		}
	cout<<endl;
	}
	return 0;
}
