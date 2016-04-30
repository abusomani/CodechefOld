#include <bits/stdc++.h>
using namespace std;

string reduce(string s)
{
	string ans = "";	
	string f = "" , l = "";	
	string f1 = "" , l1 = "";	
	bool c;
	int i;
	for(i = 0 ; i<s.length() ; i++)
	{
		if(s[i] == '.')		
		{	i++;	break;	}
		f += s[i];
	}
	
	for( ; i<s.length() ; i++)
	{
		l += s[i];
	}

	c = false;
	for(int i = 0 ; i<f.length() ; i++)
	{
		if(f[i] != '0')		{	f1 += f[i];		c = true;	}
		else if(c)			{	f1 += f[i];	}
	}
	
	c = false;
	for(int i = l.length()-1 ; i>=0 ; i--)
	{
		if(l[i] != '0')		{	l1 += l[i];		c = true;	}
		else if(c)			{	l1 += l[i];	}
	}
	reverse(l1.begin() , l1.end());

	if(l1.size())
		return f1 + "." + l1;
	else if(f1.size())
		return f1;
	else
		return "0";					//	gotcha	here
}

int main()
{
//	cout<<reduce("0.0")<<endl;
//	cout<<reduce()<<endl;
//	cout<<reduce()<<endl;
	
	int t , N;
	char c , p;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>N;
		map<char , char> mp;
		for(int i = 0 ; i<N ; i++)
		{
			cin>>c>>p;
			mp[c] = p;
		}
		cin>>str;
		for(int i = 0 ; i<str.length() ; i++)
		{
			if(mp.count(str[i]))
				str[i] = mp[str[i]];
		}
		cout<<reduce(str)<<endl;
		mp.clear();
	}
}
