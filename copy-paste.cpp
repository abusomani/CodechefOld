#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
		while(t--)
			{
				int n,x;
				cin>>n;
				int a[100007]={0},count=0;
				for(int i=0;i<n;i++)
					{
						cin>>x;
						a[x]++;
					}
				for(int i=0;i<100007;i++)
					{
						if(a[i]!=0)
						count++;
					}
				cout<<count<<endl;
			}
}
