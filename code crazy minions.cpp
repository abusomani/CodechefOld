#include<bits/stdc++.h>
using namespace std;
int main()
	{int t;
	cin>>t;
	while(t--)
		{char a[1007];
		cin>>a;
		int len=strlen(a);
		int val=1+len,pr=a[0];
		for(int i=0;i<len;i++)
			{
				if(a[i]<pr)
				val+=26+a[i]-pr;
				else
				val+=a[i]-pr;
				pr=a[i];
			
			}
		if(val>11*len)
			cout<<"NO\n";
		else
			cout<<"YES\n";
		}
	return 0;
	}
