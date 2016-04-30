#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
struct alternate
{
	int count;
	char c;
};
int compare(const void *p1,const void *p2)
{
	int l=((struct alternate*)p1)->count;
	int r=((struct alternate*)p2)->count;
	 return (l-r);
}
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	
		
	while(t--)
		{
			string s;
			cin>>s;
			alternate a[26];
		for(int i=0;i<26;i++)
		{
			a[i].c='a'+i;
			a[i].count=0;
			
		}
			int len=s.size();
			for(int i=0;i<len;i++)
				{
					a[s[i]-'a'].count++;
				}
			qsort((void*)a,26,sizeof(a[0]),compare);
		int flag=0;
		if(len==1)
		cout<<s<<endl;
		else
		{
			
		
		char ans[len],count=0,present=25,back=present-1,ch,cx;
			while(len--)
				{
					if(count%2==0)
						{
							if(a[present].count!=0)
								{
									ans[count++]=a[present].c;
									ch=a[present].c;
									a[present].count--;
								}
							else
								{
									while(a[present].count==0)
									present--;
									ans[count++]=a[present].c;
									ch=a[present].c;
									a[present].count--;
									back=present-1;
								}
						}
						else
							{
								if(a[back].count&&back>=0)
									{
									ans[count++]=a[back].c;
									cx=a[back].c;
									if(cx==ch)
										{
											flag=1;
											break;
										}
									a[back].count--;
									}
							}
							
				}
			if(flag)cout<<"-1\n";
			else
				{
					for(int i=0;i<len;i++)
						cout<<ans[i];
					cout<<endl;
				}
		}
		}
	return 0;
}
