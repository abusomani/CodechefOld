#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			
			int a,b,m;
			scanf("%d%d%d",&a,&b,&m);
			int ans=(b-a)/m;
			if(a!=0)
				ans-=1;
			printf("%d\n",ans);
				
			
				
			
		}
	
	
	
	return 0;
}

