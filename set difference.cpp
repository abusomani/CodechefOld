#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
/*long long power(long long a,long long b)
{
	long long x=1,y=a;
	while(b>0)
		{
			if(b%2==1)
				{
					x=(x*y);
					if(x>M) x%=M;
				}
				y=(y*y);
				if(y>M) y%=M;
				b/=2;
		}
		return x;
}*/
int main()
{ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			int a[n];
			for(int i=0;i<n;i++)
				{
					cin>>a[i];
				}
			sort(a,a+n);
		long long sum=0,count=1;
		for(int i=0;i<n;i++)
			{long long x=a[i];
			sum=(sum+(x*count)%M)%M;
			count=(count*2)%M;
		//	cout<<count<<endl;
			}
			count=1;
		for(int i=n-1;i>=0;i--)
			{long long x=a[i];
			sum=(sum-(x*count)%M)%M;
			count=count*2%M;
			}	
			if(sum<0)
			cout<<M+sum<<endl;
		else
		cout<<sum<<endl;
			
		}
	return 0;
}
