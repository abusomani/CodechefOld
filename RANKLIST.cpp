#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t;
	ll sum,dif,n,i,k;	
	cin>>t;
	while(t--)
	{
		k = 0;
		cin>>n>>sum;
		if(n==1)
		{	cout<<"0\n";	continue;	}
		dif =  (n*(n+1))/2 - sum;
		if(dif!=0)
		for(i = n-1 ; i>=1 ; i--)
		{
			dif-=i;
			k++;
			if(dif<=0)		break;
		}
		cout<<k<<endl;
	}
}
