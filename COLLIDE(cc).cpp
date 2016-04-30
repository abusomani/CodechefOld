#include<bits/stdc++.h>
#define M 2013
using namespace std;
struct point
{
	int x;
	int y;
	char dir;
};
int n;
void getmin(point* p,point& e)
{
	for(int i=0;i<n;i++)
	{
		
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t;		point p[M];		point e;
	cin>>t;
	while(t--)
	{
		cin>>e.x>>e.y>>e.dir;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i].x>>p[i].y>>p[i].dir;
		getmin(p,e);
	}
}
