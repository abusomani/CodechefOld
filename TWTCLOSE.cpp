#include<iostream>
#include<set>
#include<string.h>
using namespace std;
int main()
{
	int n,k,tw,i;
	string str;
	cin>>n>>k;
	set<int> s;
	for(i=0;i<k;i++)
	{
		cin>>str;
		if(str!="CLOSEALL") 
		{
			 cin>>tw;
			 if(s.find(tw)==s.end())
			 s.insert(tw);
			 else
			 s.erase(tw);
			 cout<<s.size()<<endl;
		}
		else
		{
			s.clear();
			cout<<s.size()<<endl;
		}
			 
	}
}
