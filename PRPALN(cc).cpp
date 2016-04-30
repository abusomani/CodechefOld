#include<bits/stdc++.h>
using namespace std;
bool ispalin(string& str)
{
	int l =str.length();	int k=0;
	for(int i=0;i<l/2;i++)
	{
		if(str[i]==str[l-i-1])
			k++;
	}
	if(k==l/2)			return 1;	
	else				return 0;
}
int main()
{
	int t;		string str,str1,str2;
	int lo,high;
	cin>>t;
	while(t--)
	{
		cin>>str;  
		int l = str.length();
		if(ispalin(str))		{	cout<<"YES\n";	continue;	}
		lo=0;	high=l-1;
		while(lo<high)
		{
			if(str[lo]==str[high])
				lo++,	high--;
			else
			{
				str1 = str.substr(lo,high-lo);
				str2 = str.substr(lo+1,high-lo);
				break;
			}
		}
	
		if(ispalin(str1)|ispalin(str2))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}
