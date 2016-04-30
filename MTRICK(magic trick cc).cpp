#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fast_mul(ll a,ll b,ll c)
{
	if(b==0)	
		return 0;
	
	ll ans = ( fast_mul(a,b>>1,c) ) %c;
	ans = ( ans+ans ) %c;
	if(b&1)
	{
		ans = (a + ans) %c;
	}
	return ans;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int t,n;		int	beg,end;
	bool rev;
	cin>>t;		string str;
	ll a,b,c;	ll add,mul;
	ll num[1002];
	while(t--)
	{
		cin>>n;		rev = 0;
		for(int i=0;i<n;i++)
			cin>>num[i];
		cin>>a>>b>>c;
		cin>>str;
		add = 0;	mul = 1;
		beg =0;	end=n-1;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='A')
			{	
				add = (add+a)%c;	
			}
			else if(str[i]=='M')
			{
				add = fast_mul(add,b,c);	mul = fast_mul(mul,b,c);
			}
			else
			{
				rev ^= 1;
			}
		//	cout<<mul<<"      "<<add<<endl;
			if(rev==1)		cout<<(fast_mul(num[end--],mul,c)+add%c)%c<<" ";
			else			cout<<(fast_mul(num[beg++],mul,c)+add%c)%c<<" ";
		}
	//	for(int i=0;i<n;i++)
	//		cout<<num[i]<<" ";
		
		cout<<endl;
	}
}
