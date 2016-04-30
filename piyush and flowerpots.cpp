#include<bits/stdc++.h>
using namespace std;
/*
int binarysearch(int a[],int n,int x)
{
	int low=0,high=n-1,mid,max=-1;
	while(low<=high)
		{
		mid=(low+high)/2;
		if(a[mid]==x)
			{
				if(mid>max)
					max=mid;
			}
		else if(a[mid]>x)
		high=mid-1;
		else
		low=mid+1;
		}
	return max;
}*/
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
		long long n,max=-1;
		cin>>n;
		if(n==0)
		cout<<"0\n";
		else{
		
		int arr[n],b[n];
		for(int i=0;i<n;i++)
		{
		cin>>arr[i];
		b[i]=arr[i];
		}
		sort(b,b+n);
		int a[100007]={0};
		for(int i=0;i<n;i++)
			{
				a[b[i]]=i;
			}
		for(int i=0;i<n;i++)
			{
				if(abs(a[arr[i]]-i)>max)
				max=abs(a[arr[i]]-i);
			}
		cout<<max<<endl;
		}
		
		}
	return 0;
}
