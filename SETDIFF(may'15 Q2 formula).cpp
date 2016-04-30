// May 2015  Que - 2

#include <bits/stdc++.h>
#define M 100005
#define MOD 1000000007
using namespace std;
int main()
{
	int t,n;
	long long sum , pre, suf, mul ,two; 
	int a[M];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 0; i<n ; i++)
			cin>>a[i];
		
		sort(a,a+n);
		sum = pre = 0;
		two = 1;
		for(int i = 1 ; i<n ; i++)
		{
			two = (2*two) % MOD;
			pre = (pre + (two-1)*a[i]) % MOD;	
		}
		
		mul = suf = 0;
		two = 1;
		for(int i = n-2 ; i>=0 ; i--)
		{
			mul = (mul + two) % MOD;
			two = (2*two) % MOD;
			suf = (suf + mul*a[i]) % MOD;
		}
		
		pre = pre - suf;
		if(pre<0)
			pre += MOD;
		
		cout<<pre<<endl;
	}	
}
