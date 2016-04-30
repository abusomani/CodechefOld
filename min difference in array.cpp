#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,k,i,min;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long ht[n];
		for(i=0;i<n;i++)
		cin>>ht[i];
		sort(ht,ht+n);
		min=ht[k-1]-ht[0];
		for(i=0;i<=n-k;i++)
		{
			if((ht[k+i-1]-ht[i])<min)
			min=ht[k+i-1]-ht[i];
	//		cout<<"k+"<<i<<"-1 "<<ht[k+i-1]<<"i  "<<ht[i]<<endl;
	//		cout<<"MIN"<<min<<endl;
		}
		cout<<min<<endl;
	}
}
