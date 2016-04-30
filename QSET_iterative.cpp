#include<bits/stdc++.h>
#define M 100
using namespace std;
int nc2(int n)
{
	if(n>1)
	{
		return (((n)*(n-1))/2);
	}
	else
		return 0;
}
int solve(int* modfreq)
{
	return 	(nc2((modfreq[0]+1)) + nc2(modfreq[1]) + nc2(modfreq[2]));
}
int main()
{
	int n,q,l,r,tp;
	bool flag = 0;
	int f[3];
	string a;
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin>>n>>q;
	int sum = 0;
	cin>>a;

	while(q--)
	{
		cin>>tp>>l>>r;
		if(tp==1)
		{
			l--;
			a[l] = r + '0';
		}
		else
		{
			l--;	r--;
			sum = 0;	f[0] = f[1] = f[2] = 0;
			for(int i=l;i<=r;i++)
			{
				sum += (int)a[i]-'0';
				//cout<<(int)a[i]-'0'<<"  "<<sum<<endl;
				f[sum%3]++;
			}
			cout<<solve(f)<<endl;
		}
	}
}
