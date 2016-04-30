#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{
		int s,c,k;
		cin>>s>>c>>k;
		long long ans=0;
		
		if(s==0&&c==0)
		ans=0;
		
		
		
		if(s==0&&c)
			{
			if(k==1)
			ans=pow(2,c+1)-2;
			else
			ans=0;
			}
		else if(k>s)
		ans=0;
		
		else if(c==0)
			{ 
					ans=pow(2,s+1-k)+1;
			}
		else if(s>c)
			{
				if(k>s-c)
				ans=pow(2,s-k+2)+1;
				else
				ans=pow(2,s-k+1)+1;
				
			}
		else if(c>=s)
			{
			
			
			 if(k==1)
				ans=pow(2,c+1)+1;
				
			else
				ans=pow(2,s+2-k)+1;	
			}
			
			
	cout<<ans<<endl;
	}
	return 0;
}
