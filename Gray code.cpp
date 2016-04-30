#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a;
		b[0]=a[0];
		int len=a.size();
		for(int i=0;i<len-1;i++)
			{
				int x=(a[i]-'0')^(a[i+1]-'0');
				b[i+1]=x+'0';
			}
		for(int i=0;i<len;i++)
		cout<<b[i];
		
		cout<<endl;
		
		
	}
	return 0;
}
