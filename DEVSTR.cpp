#include <bits/stdc++.h>
using namespace std;
char flip(char c)
{
	if(c == '0')
		return '1';
	return '0';
}
int main()
{
	int t,n,k,ct,chg,minv;
	char ch;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cin>>str;
		int l = str.length();
		chg = 0;
		
		if(k==1)
		{
			ch = '0';
			for(int i=0 ; i<l ; i++)
			{
				if(str[i] != ch)
					chg++;
				ch = flip(ch);
			}
			
			minv = chg;
			chg = 0;
			ch = '1';
			for(int i=0 ; i<l ; i++)
			{
				if(str[i] != ch)
					chg++;
				ch = flip(ch);
			}
			cout<<min(chg , minv)<<endl;
			
			if(chg<minv)
			{
				ch = '1';
				for(int i=0 ; i<l ; i++)
				{
					cout<<ch;	ch = flip(ch);
				}	
			}
			else
			{
				ch = '0';
				for(int i=0 ; i<l ; i++)
				{
					cout<<ch;	ch = flip(ch);
				}	
			}
			cout<<endl;
			continue;
		}
		
		ct = 1;	ch = str[0];
		
		for(int i=1 ; i<l ; i++)
		{
			if(str[i] != str[i-1])
			{
				ct = 1;		ch = str[i];	
			}
			else
			{
				ct++;
				if(ct > k)
				{
					if(i!=l-1 && str[i+1] != str[i])
					{
						str[i-1] = str[i+1];
						ct = 0;
					}
					else
					{
						str[i] = flip(str[i]);
						ct = 0;
					}
					chg++;
				}	
			}
//			cout<<i<<" : "<<ct<<endl;
		}
		cout<<chg<<endl<<str<<endl;
	}
}
