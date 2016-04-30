#include<bits/stdc++.h>
using namespace std;
int main()
	{ios_base::sync_with_stdio(false);
		int t;
		cin>>t;
		while(t--)
			{string str;
			cin>>str;
			int temp=0,i=0,local=0,local1=0;
			while(str[i]!='\0')
				{if(str[i]=='.')
					{local=1;
						while(str[++i]=='.')
						local++;
						
					if(local>local1)
						{
						temp++;	
						local1=local;
						}
					}
				i++;
				}
			cout<<temp<<endl;
			}
		return 0;
	}
