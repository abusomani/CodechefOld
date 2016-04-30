#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		
		int a[26]={0},b[26]={0},flag=0;
		if(s1.size()==s2.size())
		{
		int len=s1.size();
		for(int i=0;i<len;i++)
			{
				a[s1[i]-'a']++;
				b[s2[i]-'a']++;
			}
		for(int i=0;i<26;i++)
			{
				if(a[i]!=b[i])
				{
					cout<<"NO\n";
					flag=1;
					break;
				}
			}
		if(!flag)
		cout<<"YES\n";
		}
		
		else
		cout<<"NO\n";	
	}
	
	return 0;
}
