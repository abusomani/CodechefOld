#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	string str;
	ll ans=1;
	int save[22];
	while(1)
	{
		cin>>str;
		ans=1;
		int k=0;
		if(str[0]=='*')		break;
		int l=str.length();
		if(str[0]=='N')		{	cout<<"-1\n";	continue;	}
		for(int i=1;i<l;i++)
		{
			if(str[i]=='Y')
			{
				ans=lcm(ans,i+1);
			}
			else
			{
				save[k++]=i+1;
			}
		}
		for(int i=0;i<k;i++)
		{
			if(ans%save[i]==0)	{	ans=-1;	break;	}
		}
		cout<<ans<<endl;
	}
}
