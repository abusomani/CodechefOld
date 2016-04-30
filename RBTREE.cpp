#include<bits/stdc++.h>
using namespace std;
int getroot(int x,int y)
{
	while(x!=y)
	{
		if(x>y)
			x/=2;
		else
			y/=2;
	}
	return x;
}
int abs(int x)
{
	return ((x>0)?x:-x);
}
int main()
{
	int Q;		bool flag = 0;	
	cin>>Q;		int x, y;
	int c_x , c_y , l1 , l2 , lca , k , p;
	char c[3];
	while(Q--)
	{
		cin>>c;
		if(c[1]!='i')
		{
			cin>>x>>y;
		}
		else
		{
			flag ^= 1;
			continue;
		}

		l1 = log2(x);	l2 = log2(y);
		c_x = (l1 % 2)^(flag);	c_y = (l2 % 2)^(flag);
		k = getroot(x,y);
		if(k!=x && k!=y)
		{
			lca = log2(k);
			p = l1+l2-2*lca;
		}
		else
		{
			p = abs(l2-l1);	 
		}
		p++;
		if(p&1)
		{
			if(c[1]=='b' && c_x==0)
				cout<<p/2+1<<endl;
			else if(c[1]=='r' && c_x==1)
				cout<<p/2+1<<endl;	
			else
				cout<<p/2<<endl;	
		}
		else
		{
			cout<<p/2<<endl;
		}
	}
}
