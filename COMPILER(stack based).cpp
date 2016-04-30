// CODECHEF COMPILER may '14
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t , ans;
	string str;
	cin>>t;
	while(t--)
	{
		cin>>str;
		ans = 0;
		stack<char> st;
		int l = str.length();
		for(int i=0;i<l;i++)
		{
			if(str[i] == '<')
				st.push(str[i]);
			else
			{
				if(!st.empty() and st.top() == '<')
				{
					st.pop();
					if(st.empty())
						ans = i+1;
				}
				else
					st.push('>');
			}
		}
		cout<<ans<<endl;
	}
}
