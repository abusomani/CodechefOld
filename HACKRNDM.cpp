#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,n,k,p=1,count=0;
	cin>>n>>k;
	int a[n];
	for(i=0 ; i<n ; i++)
	cin>>a[i];
	sort(a,a+n);
	for(i=0 ; i<n ; i++)
	{
		for(j=i+1 ; j<n ; j++)
		{
			if((a[j]-a[i])>=k)
			{
				if(a[j]-a[i]==k)
				{     count++;  break; }
				else {       break;}
			}
		}
	}
	cout<<count<<endl;
}
