#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,max=-1;
		cin>>n;
		int a[100007]={0};
		for(int i=0;i<n;i++)
			{
				cin>>x;
				a[x]++;
			}
		for(int i=0;i<100007;i++)
			{
				if(a[i]>max)
				max=a[i];
			}
		cout<<n-max<<endl;
	}
	return 0;
}
