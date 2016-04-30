#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		
		string s;
		cin>>s;
		char start=s[0],second=s[1];
		if(start==second)
			cout<<"NO\n";
		else
			{int len=s.size(),flag=0;
				for(int i=0;i<len;i++)
					{
						if(i%2==0)
							{
								if(s[i]!=start)
									{
										cout<<"NO\n";
										flag=1;
										break;
									}
								
							}
						else
							{
								if(s[i]!=second)
									{
										cout<<"NO\n";
										flag=1;
										break;
									}
								
							}
					}
				if(!flag)
					cout<<"YES\n";
			}
		
	}
	
	return 0;
}
