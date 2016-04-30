#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{int t,i,j,n,r[127],len,dot;
char c,p,s[1000009];
cin>>t;
	while(t--)
		{cin>>n;
		getchar();
		for(i=0;i<127;i++)
		r[i]=i;
		for(i=0;i<n;i++)
			{cin>>c>>p;
			getchar();
			r[c]=p;
			}
		gets(s);
		dot=0;
		for(i=0;s[i]!='\0';i++)
			{s[i]=r[s[i]];
			if(s[i]=='.')
			dot=1;
			}
		len=--i;
		for(i=0;s[i]=='0'&&i<=len;i++);
		j=len;
		for(;s[j]=='0'&&j>=i;j--);
		if((s[i]=='.'&&s[j]=='.')||(j<i))
		cout<<"0"<<endl;
		else if(s[i]!='.'&&s[j]=='.')
			{s[j]='\0';
			printf("%s\n",s+i);
			}
		else
		{s[++j]='\0';
		printf("%s\n",s+i);
		}
	}
		
return 0;		
		
}
