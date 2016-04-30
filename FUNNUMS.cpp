//      template by Utkarsh trivedi
//      problem id-    FUNNUMS                   Based on-  MATH REASONING PERMUTATION
#include<stdio.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define nl   printf("\n")
#define chk   printf("hello    ")
typedef long long ll;
typedef unsigned long long ull;

#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

unsigned long long fact[16];
ll rank(char* str)
{
	int i,j,l=strlen(str),count;
	ll sum=0;
	char c;
	for(i=0;i<l;i++)
	{
		c=str[i];       count=0;
		for(j=i+1;j<l;j++)
		{
			if(c>str[j])
			{ count++;}
		}
		sum+=(count)*fact[l-i-1];
	}
	return (sum+1);
}
int main()
{
	char str[20];
	ll add,k;
	string:: iterator p;
	int t,l,i;
	s(t);
	fact[0]=1;
	for(i=1;i<=15;i++)
	fact[i]=i*fact[i-1];
	while(t--)
	{
		cin>>str>>add;
		l=strlen(str);
		if(add==0)     {     cout<<str<<endl;     continue;     }
		if(l==1)  {  cout<<str<<endl;   continue;      }
		if(l==2)  {  if(add==1)  cout<<str[1]<<str[0]<<endl;   continue;  }
		add=rank(str)+add;
	//	cout<<add<<endl;
		sort(str,str+l);
		string str1(str);
		while(1)
		{
			k=add/fact[l-1];
			if(add%fact[l-1]==0)  k--;          // special case when add is divisible it gives one more to required.
			cout<<str1[k];
			p=str1.begin()+k;
			str1.erase(p);
			add=add%fact[l-1];
			l--;
		/*	cout<<"(";
			for(i=0;i<l;i++)   cout<<str1[i];
			cout<<")";*/
			if(l==2)
			{
				if(add==1)        cout<<str1[0]<<str1[1];
				else if(add==0)   cout<<str1[1]<<str1[0];
				break;
			}
			if(add==0)							// special case when number is last in its part as 3421(after 3), 625431(after 2)   so direct reverse because add become 0 
			{
				for(i=l-1;i>=0;i--)
				cout<<str1[i];
				//cout<<endl;
				break;
			}  
		}
		nl;
	}

}
