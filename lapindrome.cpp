#include<iostream>
#include<string.h>
#define e 97
using namespace std;
void show(int* f)
{
	for(int i=0;i<26;i++)
	cout<<char(i+e)<<"  "<<f[i]<<endl;
}
int main()
{
	int t,l,mid,i;
	cin>>t;
	while(t--)
	{
		char str[1000];
		int f1[26]={0},f2[26]={0};
		cin>>str;
		l=strlen(str);
		mid=l/2;
		if(l%2==0)
		{
			for(i=0;i<mid;i++)
			f1[str[i]-e]++;
			for(i=mid;i<=l-1;i++)
			f2[str[i]-e]++;
			//show(f1);   cout<<endl;   show(f2);
			for(i=0;i<26;i++)
			{
				if(f1[i]!=f2[i])
				break;
			}
			if(i==26)  cout<<"YES\n";
			else   cout<<"NO\n";
		}
		else
		{
			for(i=0;i<mid;i++)
			f1[str[i]-e]++;
			for(i=mid+1;i<=l-1;i++)
			f2[str[i]-e]++;
			//show(f1);   cout<<endl;   show(f2);
			for(i=0;i<26;i++)
			{
				if(f1[i]!=f2[i])
				break;
			}
			if(i==26)  cout<<"YES\n";
			else   cout<<"NO\n";
		}
	}
}
