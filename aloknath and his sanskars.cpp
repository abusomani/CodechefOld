#include<bits/stdc++.h>
using namespace std;
int main()
	{int t;
	cin>>t;
	while(t--)
		{int n,k,i,flag=0;
		cin>>n>>k;
		long long sum=0,temp=0,a[n];
		for(i=0;i<n;i++)
			{cin>>a[i];
			sum+=a[i];
			}
		sort(a,a+i);
		sum=sum/k;
		if(a[n-1]>sum)
			cout<<"no"<<endl;
		else
			{if(a[n-1]<sum)
				{
				int low=0,high=n-1;
				while(low<=high)
					{temp+=a[high--];
						if(temp==sum)
							temp=0;
					if(temp<sum)
						temp=a[low++];
					if(temp>sum)
						{flag=1;break;}		
					}
				}
			else
				{int low=0,high=n-2;
				while(low<=high)
					{temp+=a[high--];
						if(temp==sum)
							temp=0;
					if(temp<sum)
						temp=a[low++];
					if(temp>sum)
						{flag=1;break;}		
					}
				}
			
			if(flag)
			cout<<"no"<<endl;
			else
			cout<<"yes"<<endl;
		}
		
		}
		return 0;
	}
