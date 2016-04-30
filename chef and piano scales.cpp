#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			char s[107];
			cin>>s;
			int value=0,N;
			int len=strlen(s);
			for(int i=0;i<len;i++)
				{
					if(s[i]=='T')
						value+=2;
					else if(s[i]=='S')
						value++;
						
				}
			cin>>N;
			
			long long steps=0,temp=value;
			while(value<=12*N)
				{
					steps+=12*N-value;
					value+=temp;
				}
			cout<<steps<<endl;
		}
}
