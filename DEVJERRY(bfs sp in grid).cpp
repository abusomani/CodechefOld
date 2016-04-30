#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

bool visit[25][25];
int dis[25][25];
int	n, sx, sy , ex, ey, bx, by;

bool ok(int a , int b)
{
	if(a<=0 or a>n or b<=0 or b>n)
		return false;
	if(visit[a][b])
		return false;
	if(a == bx and b == by)
		return false;
	return true;
}

int bfs(int a , int b)
{
	queue<ii> q;
	q.push(ii(a,b));
	ii t;
	memset(&visit , 0 , sizeof(visit));
	dis[a][b] = 0;
	visit[a][b] = true;
	while(!q.empty())
	{
		t = q.front();		q.pop();
		a = t.first;		b = t.second;
		if(a == ex and b == ey)
			return dis[a][b];
		
		if(ok(a-1 , b))		{	visit[a-1][b] = true;	dis[a-1][b] = 1 + dis[a][b];	q.push(ii(a-1,b));		}
		if(ok(a , b-1))		{	visit[a][b-1] = true;	dis[a][b-1] = 1 + dis[a][b];	q.push(ii(a,b-1));		}
		if(ok(a , b+1))		{	visit[a][b+1] = true;	dis[a][b+1] = 1 + dis[a][b];	q.push(ii(a,b+1));		}
		if(ok(a+1 , b))		{	visit[a+1][b] = true;	dis[a+1][b] = 1 + dis[a][b];	q.push(ii(a+1,b));		}
	}
}

int main()
{
	int Cases;
	cin>>Cases;
	while(Cases--)
	{
		cin>>n>>sx>>sy>>ex>>ey>>bx>>by;
		cout<<bfs(sx , sy)<<endl;
	}	
}
