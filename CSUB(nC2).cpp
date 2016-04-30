#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t , l;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>l;
		cin>>str;
		long long n = 0;
		for(int i = 0 ; i<l ; i++)
			if(str[i] == '1')
				n++;
		
		long long ans = (long long)(n*(n+1))/2 ;
		cout<<ans<<endl;
	}	
}
