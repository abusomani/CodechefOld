#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	int q;
	cin>>q;
	while(q--)
	{
		char A,B;
		int l,r;
		cin>>A>>B>>l>>r;
		int x[100005],y[100005],X=0,Y=0,count=0;
		for(int i=l-1;i<r;i++)
			{
				if(s[i]==A)
				x[X++]=i;
				else if(s[i]==B)
				y[Y++]=i;
			}
		for(int i=0;i<X;i++)
			{
				for(int j=0;j<Y;j++)
					{
						if(x[i]<y[j])
						count++;
					}
			}
		cout<<count<<endl;
	}
	
	return 0;
	
}
