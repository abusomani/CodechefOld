#include<bits/stdc++.h>
using namespace std;
int maxLengthNonzeroProductSubarray(int a[],int size)
{
	int length=0,maxlengthtillhere=-1;
	for(int i=0;i<size;i++)
		{
			if(a[i]!=0)
				{
					length++;
				}
			else if(a[i]==0)
				{
					if(maxlengthtillhere<length)
						{
							maxlengthtillhere=length;
							
						}
					length=0;
				}
		}
	if(maxlengthtillhere<length)
						{
							maxlengthtillhere=length;
							
						}
		return maxlengthtillhere;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
	cout<<maxLengthNonzeroProductSubarray(a,n);
	return 0;
}

