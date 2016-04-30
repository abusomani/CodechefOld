#include<bits/stdc++.h>
using namespace std;
long long gcdr(long long a,long long b)
{

  if ( a==0 ) return b;
  return gcdr ( b%a, a );

}
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		{long long a,b,gcd;
		cin>>a>>b;
		long long max1=max(a,b);
		gcd=gcdr(a,b);
		max1=(max1/gcd)-2;
		if(a==b)
		cout<<"0"<<endl;
		else
		cout<<max1<<endl;
		}
	return 0;	
}
