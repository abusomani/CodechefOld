#include<iostream>
#include<ctype.h>
#include<stack>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{char a[400];
	cin>>a;
	stack<char>S;
	for(int i=0;a[i]!='\0';i++)
		{if(isalpha(a[i]))
		cout<<a[i];
		else if(a[i]==')')
			{if(!S.empty())
			{
			cout<<S.top();
			S.pop();
			}
			}
		else if(a[i]=='(')
			continue;
		else
		S.push(a[i]);
		}
	cout<<endl;
	}
return 0;
}
