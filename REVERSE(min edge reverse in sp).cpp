//	Add reverse edge of each original edge in the graph. Give reverse edge a weight=1 and all 
//	original edges a weight of 0. Now, the length of the shortest path will give us the answer.
//	If shortest path is p: it means we used p reverse edges in the shortest path. So, it is answer. 

#include<bits/stdc++.h>
#define MAX 2147483647
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
int main()
{
	int n,m;	int a,b,wt;
	cin>>n>>m;
	vvii g(n);
	vi dis(n,MAX);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;	 a--;	b--;
		g[a].push_back(ii(b,0));
		g[b].push_back(ii(a,1));		    	//   adding reverse edge with 1 length 
	}
	
	
	set<ii> st;	
	st.insert(ii(0,0));						    //   Starting from first vertex
	dis[0] = 0;		ii k;
	while(!st.empty())
	{
		k = *st.begin();		st.erase(st.begin());
		a = k.second;
		for(int i=0;i<g[a].size();i++)
		{
			b = g[a][i].first;		wt = g[a][i].second;
			if(dis[b] > dis[a] + wt)
			{
				if(dis[b]!=MAX)		st.erase(st.find(ii(dis[b],b)));
				dis[b] = dis[a] + wt;
				st.insert(ii(dis[b],b));
			}	
		}
	}
	if(dis[n-1]==MAX)		cout<<"-1\n";
	else					cout<<dis[n-1]<<endl;
	g.clear();
}
