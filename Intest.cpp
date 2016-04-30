#include<iostream>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int n,k,count=0,x;
cin>>n>>k;
for(int i=0;i<n;i++)
	{cin>>x;
	if(x%k==0)
	count++;
	}
cout<<count;
return 0;
}
