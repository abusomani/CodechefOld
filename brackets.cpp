#include<bits/stdc++.h>
using namespace std;
int function(char s[])
	{int balance=0,max_balance=0;
		for(int i=0;i<strlen(s);i++)
			{if(s[i]=='(')
				balance+=1;
			if(s[i]==')')
				balance-=1;
			max_balance=max(max_balance,balance);
			//cout<<max_balance<<" "<<balance<<endl;
			}
		return max_balance;
	}
int valid(char s[])
	{int i=0,balance=0;
		while(s[i]!='\0')
			{if(s[i]==')')
				balance+=1;
			else if(s[i]=='(')
				balance-=1;
			i++;
			}
	return balance;
	}
int main()
{int t;
scanf("%d",&t);
	while(t--)
		{char s[100007];
		cin>>s;
		if(!valid(s)&&(s[0]!=')'||s[strlen(s)-1]!='('))
		{
		
		int count=function(s);
		//cout<<count;
		for(int i=0;i<count;i++)
			cout<<"(";
			
		for(int i=0;i<count;i++)
			cout<<")";
		}
		cout<<endl;
		}
		return 0;
}
