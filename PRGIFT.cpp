#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,k,a;
	cin>>t;
	while(t--)
	{
		int ct = 0;
		cin>>n>>k;
		for(int i = 0 ; i<n ; i++)
		{
			cin>>a;
			if(a%2 == 0)
				ct++;
		}
		if(k==0 && ct==n)
			ct = -1;
		
		if(ct>=k)		cout<<"YES";
		else			cout<<"NO";
		cout<<endl;
	}
}
