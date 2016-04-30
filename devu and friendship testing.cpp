#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		int a[102]={0},x,count=0;
		for(int i=0;i<n;i++)
			{
				cin>>x;
				a[x]++;
			}	
		for(int i=1;i<=100;i++)
			if(a[i]!=0)count++;
			
		cout<<count<<endl;
	}	
	return 0;
}
