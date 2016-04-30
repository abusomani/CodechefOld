//	chefbm

#include <bits/stdc++.h>
#define M 10000
using namespace std;
typedef pair<int,int> ii;

struct info
{
	int x,y,freq;	
	info(int x,int y,int f) : x(x) , y(y) , freq(f)
	{}
	info()
	{}
};

bool cmp(info a, info b)
{
	if(a.x == b.x)
		return a.y > b.y;
	return a.x < b.x;	
}

int main()
{
//	freopen("E://temp.txt" , "r" , stdin);
	int n,m,p1,x,y,freq;
	int ans[M];
	bool visit[M];
	
	map<ii , int> mp;
	vector<info> v;
	info last;
	
	memset(&visit,0,sizeof(visit));
	
	cin>>n>>m>>p1;
	for(int i = 0 ; i<p1 ; i++)
	{
		cin>>x>>y;
		if(mp.count(ii(x,y)) == 1)
			mp[ii(x,y)]++;
		else
			mp[ii(x,y)] = 1;
	}
	
	map<ii , int> :: iterator p = mp.begin();
	while(p != mp.end())
	{
		x = p->first.first;		 y = p->first.second;
		freq = p->second;
		v.push_back(info(x,y,freq));
		p++;
	}
	
	sort(v.begin() , v.end() , cmp);
	
	
//	for(int i = 0 ; i<v.size() ; i++)
//		cout<<v[i].x<<"  "<<v[i].y<<"  "<<v[i].freq<<endl;
	
	for(int i = 1 ; i<=n ; i++)
	{
		ans[i] = -2;
	}
	
	for(int i = 0 ; i<v.size() ; i++)
	{
		x = v[i].x;  y = v[i].y	;	freq = v[i].freq;	
		if(visit[x])
		{	
			if(ans[x] == -1)
				continue;
				
			if(last.y == y+1)
			{
				if(last.freq < freq-1)
					ans[x] = -1;
				else
				{
					ans[x] += last.freq - freq + 1;
				}
			}
			else
			{
				if(freq > 1)
					ans[x] = -1;
				else
				{
					ans[x] += last.y - y - 1;
					ans[x] += last.freq;
				}
			}
		}
		else
		{
			ans[x] = 0;
			visit[x] = true;
			if(i>0)
			{
				if(ans[last.x] != -1 && last.y != 1)
					ans[last.x] += last.y + last.freq  - 1;
			}
			if(y != m)
			{
				if(freq > 1)
					ans[x] = -1;
				else
					ans[x] += m-y-1;
			}
		}
		last = v[i];
	}
	
	if(ans[last.x] != -1 && last.y != 1)
		ans[last.x] += last.y + last.freq - 1;
	
	for(int i = 1 ; i<=n ; i++)
	{
		if(ans[i] == -2)
			cout<<(m-1)<<endl;
		else
			cout<<ans[i]<<endl;
	}
}
