#include<iostream>
#include<string.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
{char a[200];
cin>>a;
int x=0,count;
	for(int i=0;a[i]!='\0';i++)
		{count=1;
		if(a[i]=='*')
		continue;
		for(int j=i+1;a[j]!='\0';j++)
			{if(a[i]==a[j])
				{a[j]='*';
				count++;
				}
			}
			a[i]='*';
			x+=(count/2)+(count%2);
		}
	cout<<x<<endl;
}
return 0;
}
