#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{if(b==0)
	return a;
else 
	return gcd(b,a%b);
}
int main()
{int a,b;
cin>>a>>b;
int x=gcd(a,b);
cout<<x<<endl;
	int t;
	cin>>t;
	while(t--)
		{int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		}
	return 0;
}
