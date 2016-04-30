#include <bits/stdc++.h>
#define M 200
using namespace std;

int g[M][M];
int parent[M];
bool visit[M];
int N;					//	Number of vertices in graph
bool bfs(int s,int t)
{
	int v, tmp;
	memset(&visit,0,sizeof(visit));
	queue<int> q;
	q.push(s);		visit[s] = 1;		parent[s] = -1;
	while(!q.empty())
	{
		tmp = q.front();		q.pop();
		if(tmp == t)			return 1;
		for(int i=0;i<N;i++)
		{
			v = i;
			if(g[tmp][i]>0 and !visit[v])
			{
				visit[v] = 1;
				parent[v] = tmp;
				q.push(v);	
			}
		}
	}
	return 0;
}
int getmaxflow(int s,int t)					//	edmond - karp implementation
{
	int u,v;
	int min_flow;
	int max_flow = 0;
	while(bfs(s,t))
	{
		min_flow = INT_MAX;
		for(int v=t ; v!=s ; v=parent[v])
		{
			u = parent[v];
			min_flow = min(min_flow , g[u][v]);
		}
		
		for(int v=t ; v!=s ; v=parent[v])
		{
			u = parent[v];
			g[u][v] -= min_flow;
			g[v][u] += min_flow;
		}
		max_flow += min_flow;
	}
	return max_flow;
}

int main()
{
	int t , n , c[M] , ct;
	int mp[M];
	int ans[M];
	int sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(&g,0,sizeof(g));
		
		sum = 0;
		for(int i = 1; i<=n ; i++)
		{
			cin>>c[i];
			sum += c[i];
		}
		if(sum != n)
		{
			cout<<-1<<endl;
			continue;
		}
		
		ct = n+1;
		
		for(int i = 1 ; i<=n ; i++)
			g[0][i] = 1;
		
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = 0 ; j<c[i] ; j++)
			{
				mp[ct] = i;
				g[ct][2*n+1] = 1;
				ct++;
			}
		}
				
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = n+1 ; j<=2*n ; j++)
			{
				if(mp[j] != i)
					g[i][j] = 1;
			}
		}
		
//		for(int i = 0 ; i<=2*n+1 ; i++)
//		{
//			for(int j = 0 ; j<=2*n+1 ; j++)
//				cout<<g[i][j]<<" ";
//			cout<<endl;
//		}
		
		N = 2*n + 2;	
		int val = getmaxflow(0,2*n+1);		
	
		if(val != n)
		{
			cout<<-1<<endl;
			goto no;
		}
		
//		for(int i = 0 ; i<=2*n+1 ; i++)
//		{
//			for(int j = 0 ; j<=2*n+1 ; j++)
//				cout<<g[i][j]<<" ";
//			cout<<endl;
//		}
		
		for(int i = 1 ; i<=n ; i++)
		{
			for(int j = n+1 ; j<=2*n ; j++)
			{
				if(g[j][i] == 1)					
				{
					ans[i] = mp[j]; 
				}
			}
		}	
		
		for(int i = 1 ; i<=n ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		
		no:
			;
	}
}
