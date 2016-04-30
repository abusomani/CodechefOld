#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;

while(t--)
{
	int n,a[1003]={0},x,count=0;
	cin>>n;
	for(int i=0;i<n;i++)
		{cin>>x;
		a[x]++;
		}
	for(int i=0;i<1003;i++)
		{if(a[i]>1)
		count++;
		}
	cout<<count<<endl;
}
	return 0;
}
