#include<bits/stdc++.h>
using namespace std;
void func(int a[26],string s,int n)
{
	int count=0,i=0,flag=0;char ch='A';
	
	while(count<26)
	{
	if(a[count]==0)
	count++;
	
	else if(a[count]!=0)
		{
			if('A'+count==s[i])
				{
				
				a[count]--;
				cout<<s[i++];	
				}
			else
				{
					cout<<(char)(ch+count);
					a[count]--;
					
					char h=(char)(ch+count);
					while(i<n)
						{
							if(s[i]==h&&flag==0)
								{
									flag=1;
									i++;
									continue;
								}
							else
								{
									cout<<s[i++];
								}
							
							
						}
					if(flag)
					break;
				}
		
				
		}
	else if(flag)
	break;
	}
}
int main()
{int t;
cin>>t;
while(t--)
	{
		int a[26]={0},n;
		cin>>n;
		string s;
		cin>>s;
		
		for(int i=0;i<n;i++)
			{
				a[s[i]-'A']++;
			}
	func(a,s,n);
	cout<<endl;
		
		
	}
	return 0;
}
