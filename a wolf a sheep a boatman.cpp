#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
scanf("%d",&t);
	while(t--)
		{int n,m,eater[1000]={0},eaten[1000]={0},x,y,flag=0;
		scanf("%d%d",&n,&m);
			for(int i=0;i<m;i++)
				{scanf("%d%d",&x,&y);
				eaten[x]++;
				eater[y]++;
				}
			for(int i=1;i<=n;i++)
				{if(eater[i]==n-1||eaten[i]==n-1)
					{cout<<"NO"<<endl;
					flag=1;
					break;
					}
				}
		if(!flag)
			cout<<"YES"<<endl;
		}
return 0;
}
