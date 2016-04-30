#include<bits/stdc++.h>
using namespace std;
/*int BinarySearch(int a[],int size,int x)
{
int low=0,high=size-1,mid;
	while(low<=high)
		{
			mid=(low+high)/2;
			if(a[mid]==x)
				return mid;
			else if(a[mid]>x)
				high=mid-1;
			else
				low=mid+1;
		}
	return 0;

}*/
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			int n,x;
			cin>>n;
			int a[500007]={0};
			for(int i=1;i<=n-1;i++)
				{
					cin>>x;
					a[x]++;
				}
			for(int i=1;i<=n;i++)
				{
					if(a[i]==0)
						{
							cout<<i<<endl;
							break;
						}
				}
			
			
	}
	
	return 0;
}
