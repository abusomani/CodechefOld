#include<iostream>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
{int n,c,sum=0,x;
cin>>n>>c;
for(int i=0;i<n;i++)
	{
	cin>>x;
	sum+=x;
	}
	if(sum<=c)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}
return 0;
}
