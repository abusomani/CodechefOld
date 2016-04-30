#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	char a[100007],b[100007],c='+',d='-';
	for(int i=0;i<100007;i++)
		{
			if(i%2==0)
				{
					a[i]=c;
					b[i]=d;
				}
			else
				{
					a[i]=d;
					b[i]=c;
				}
		}
	while(t--)
		{
			string ch;
			cin>>ch;
			int len=ch.size(),count1=0,count2=0;
			for(int i=0;i<len;i++)
				{
					if(ch[i]!=a[i])
						count1++;
						
					
					 else if(ch[i]!=b[i])
					 	count2++;	
				}
			cout<<min(count1,count2)<<endl;
		}
	return 0;
}
