#include<bits/stdc++.h>
using namespace std;
//3 5 9
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			int x,count=0;
			for(int i=1;i<=n;i++)
				{
					cin>>x;
					count+=x/i;
				}
			if(count%2)
			cout<<"ALICE\n";
			else
			cout<<"BOB\n";
		}
	return 0;
}
