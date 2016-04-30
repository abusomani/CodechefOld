#include<bits/stdc++.h>
#define MAX 2147483647
using namespace std;
#define M 100005
bool visit[M];
int dis[M];
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	vector<int> val[10];
	string str;
	int t,k;
	cin>>str;
	memset(&visit,0,sizeof(visit));
	int l = str.length();
	for(int i=0;i<l;i++)
	{
		val[str[i]-'0'].push_back(i);
	}
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	visit[0] = 1;
	while(!q.empty())
	{
		t = q.front();		q.pop();
	//	cout<<"$"<<str[t]<<endl;
		if(t == l-1)		break;
		for(int i=0;i<val[str[t]-'0'].size();i++)
		{
			k = val[str[t]-'0'][i];
			if(!visit[k])
			{
				visit[k] = 1;
				dis[k] = dis[t] + 1;
				q.push(k);
			}
		}
		val[str[t]-'0'].clear();			//  
		if(t>0 && !visit[t - 1])
		{
			visit[t - 1] = 1;
			dis[t-1] = dis[t] + 1;
			q.push(t-1);
		//	cout<<str[t-1]<<"  ";
		}
		if(t<l && !visit[t + 1])
		{
			visit[t+1] = 1;
			dis[t+1] = dis[t] + 1;
			q.push(t+1);
		//	cout<<str[t+1]<<"  ";	
		}
	}
	cout<<dis[l-1]<<endl;
}
