#include<bits/stdc++.h>
using namespace std;
void swap(string &s,int a,int b)
{
	char t=s[a];
	s[a]=s[b];
	s[b]=t;
}
int main()
{char B[100007],G[100007];
for(int i=0;i<100007;i++)
	{
		if(i%2==0)
			{
				B[i]='B';
				G[i]='G';
				
			}
			else
				{
					B[i]='G';
					G[i]='B';
				
				}
	}
	int t;
	cin>>t;
	while(t--)
		{
			int type,a[2]={0};
			cin>>type;
			string s;
			cin>>s;
			long long ans=0;
			int len=s.size();
			for(int i=0;i<len;i++)
				{
					if(s[i]=='B')
					a[0]++;
					else
					a[1]++;
				}
			int x=a[0]-a[1];	
			if(x==0)
				{
				if(s[0]=='B')
					{int curr=-1,next=-1;
						for(int i=1;i<len;i++)
							{
								if(s[i]!=B[i])
									{
										if(curr=-1)
											curr=i;
										else
											{
												
											}
									}
							}
					}
				
				}
			else
			cout<<"-1\n";
		}
	return 0;
}
