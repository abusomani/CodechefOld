#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		long long a[n],b[n],idsum=0,sum=0,zeroidsum=0;
		for(int i=0;i<n;i++)
			{
				cin>>a[i]>>b[i];
				if(b[i]!=0)
					{idsum+=a[i];
					sum+=b[i];
					}
				else
					{zeroidsum+=a[i];
					}
			}
		sum=sum-zeroidsum;
		idsum-=sum;
		cout<<idsum<<endl;
		
	}
	return 0;
}
