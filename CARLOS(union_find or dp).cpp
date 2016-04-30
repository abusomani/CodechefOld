//	Codechef Carlos

#include <bits/stdc++.h>
using namespace std;
#define M 2005

int n;
int s[M];
int dp[M];
set<int> st[M];
set<int>::iterator it;
int a[M];

int find(int x)					// 	non-recursive
{	
	if(s[x]<0)					// 	for recursive in else - return s[x] = find(s[x])
		return x;
	else
		return s[x] = find(s[x]);	
}
void dounion( int root1,int root2)
{
	root1 = find(root1);
	root2 = find(root2);
	if(root1 == root2)
		return ;
	if(s[root1]>=s[root2])
	{
		s[root2]+=s[root1];
		s[root1]=root2;
	}
	else
	{
		s[root1]+=s[root2];
		s[root2]=root1;
	}
}

void makeset(int m)
{
	int k;
	for(int i=1;i<=m;i++)
	{
		k = find(a[i]);
		st[k].insert(a[i]);
	}
}

void showset(int m)
{
	for(int i=1;i<=m;i++)
	{
		it = st[i].begin();
		cout<<i<<"  :  ";
		while( it != st[i].end() )
		{
			cout<<*it<<"  ";
			it++;
		}
		cout<<endl;
	}
}

int getnext(int x , int num)
{
	int pos = find(x);
	it = st[pos].lower_bound(num);
	if(it == st[pos].end())
		return -1;
	else
		return *(it) ;
}

int solve(int pos)
{
//	cout<<pos<<endl;
	int nochg,chg,keep;
	chg = nochg = INT_MAX;
	if(dp[pos] != -1)
		return dp[pos];
		
	if(a[pos] >= a[pos-1] && pos<n)
		nochg = solve(pos+1);
	else
		nochg = INT_MAX;
	
	keep = a[pos];		
	a[pos] = getnext(keep,a[pos-1]);
	
	if(keep != a[pos] && a[pos] != -1)
		chg = 1;
	else
		chg = 0;
	
	if(a[pos] == -1)
		chg = INT_MAX;
	else if(a[pos] < a[pos-1])
		chg = INT_MAX;	
	else 
	{
		if(pos<n)
			chg += solve(pos+1);
	}
	a[pos] = keep;
	dp[pos] = min(nochg , chg); 
	return dp[pos];
}

int main()
{
	int t,m,k,u,v,ans;
	freopen("E://Test//in.txt","r",stdin);
	freopen("E://Test//out.txt","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>m>>k>>n;
		memset(&s,-1,sizeof(s));
		memset(&dp,-1,sizeof(dp));
		for(int i=0;i<k;i++)
		{
			cin>>u>>v;
			dounion(u,v);
		}
		
		for(int i=1;i<=n;i++)
			cin>>a[i];
			
		a[0] = INT_MIN;
		makeset(m);	
		showset(m);
		
		ans = solve(1);
		if(ans < -1)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
			
		for(int i=1;i<=n;i++)
			st[a[i]].clear();
	}
}

/*
http://ideone.com/ascTrt
1
11 6 11
4 5
2 6
1 6
4 6
3 7
10 11
4 5 6 2 7 1 3 8 9 10 11
*/
