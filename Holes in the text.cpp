#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int sum=0;
	char a[100];
	cin>>a;
	for(int i=0;a[i]!='\0';i++)
		{
		if((a[i]=='A')||(a[i]=='D')||(a[i]=='O')||(a[i]=='Q')||(a[i]=='P')||(a[i]=='R'))
		sum++;
		else if(a[i]=='B')
		sum+=2;
		}
	cout<<sum<<endl;
	}
return 0;	
}
