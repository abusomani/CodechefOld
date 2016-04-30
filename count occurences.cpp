#include<bits/stdc++.h>
using namespace std;
int countSubstring(const string& str, const string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset !=string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			string s,sub="hi";
			cin>>s;
			cout<<countSubstring(s,sub)<<endl;
			
	}
	
	return 0;
}
