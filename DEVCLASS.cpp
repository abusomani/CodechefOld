#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int abs(int x)
{
	return (x>0)?x:-x;
}

int type;
string str;

ll solve(stack<int>& qg , stack<int>& qb)
{
	int a,b,c;
	ll cost = 0;
	if(type == 0)
		return qg.size();
	
	while(!qb.empty())
	{
		a = qb.top();		qb.pop();
		b = qg.top();		qg.pop();
		c = abs(b-a);
		cost += c;
		/*
		if(type == 1)
			cost += c;
		else
			cost += 4*(c/2) + c%2;	
		*/
	}
	return cost;
}

ll start_b()
{
	stack<int> qb;
	stack<int> qg;
	int l = str.length();
	for (int i = 0; i < l; ++i)
	{
		if(i%2==0)
		{
			if(str[i] != 'G')
			{
				qg.push(i);
			}	
		}
		else
		{
			if(str[i] != 'B')
			{	
				qb.push(i);
			}
		}
	}
	return solve(qb,qg);
}
ll start_g()
{
	stack<int> qb;
	stack<int> qg;
	int l = str.length();
	for (int i = 0; i < l; ++i)
	{
		if(i%2==0)
		{
			if(str[i] != 'B')
				qb.push(i);
		}
		else
		{
			if(str[i] != 'G')
				qg.push(i);
		}
	}
	
	return solve(qb,qg);
}

int main()
{
	int t,g,b;
	ll cost1,cost2;
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	
	cin>>t;
	while(t--)
	{
		g = b = 0;
		cin>>type;
		cin>>str;
		int l = str.length();
		for (int i = 0; i < l; ++i)
		{
			if(str[i] == 'G')	g++;
			else				b++;
		}
		
	
		if(l%2==1 and abs(g-b) != 1)
		{	cout<<"-1"<<endl;	continue;	}
		if(l%2==0 and g!=b)
		{	cout<<"-1"<<endl;	continue;	}
		
		if(l%2 == 0)
		{
			cost1 = start_b();
			cost2 = start_g();
		//	cout<<cost1<<"  "<<cost2<<endl;
			cout<<min(cost1,cost2)<<endl;
		}
		else
		{
			if(g>b)
				cost1 = start_b();
			else	
				cost1 = start_g();
			cout<<cost1<<endl;
		}
	}
}
