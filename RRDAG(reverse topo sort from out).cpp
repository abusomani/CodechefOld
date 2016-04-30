#include <bits/stdc++.h>
#define M 1505
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int N , in[M] , out[M] , k;
char g[M][M];
vector<int> topoSort;
vector<ii> ans;
	
void topo()
{
	set< int , greater<int> > q;
	int K;
	for (int i = 0; i < N; ++i)
	{
		if(out[i] == 0)
			q.insert(i);
	}
	while(!q.empty())
	{
		K = *q.begin();		q.erase(q.begin());
//		cout<<K<<endl;
		topoSort.push_back(K);
		for (int i = 0; i < N; ++i)
		{
			if(g[i][K] == '1' && --out[i] == 0)
				q.insert(i);
		}
	}
	reverse(topoSort.begin(), topoSort.end());
}

int main()
{
	scanf("%d" , &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s" , g[i]);
		for (int j = 0; j < N; ++j)
		{
			if(g[i][j] == '1')
			{
				in[j]++;
				out[i]++;
			}
		}
	}

	topo();

	for (int i = 0; i < topoSort.size(); ++i)
	{
		for (int j = i+1; j < topoSort.size(); ++j)
		{
			if(g[topoSort[i]][topoSort[j]] == '0')
				ans.push_back(ii(topoSort[i] , topoSort[j]));
		}
	}

	sort(ans.begin() , ans.end());
	printf("%d\n" , ans.size());
	
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n" , ans[i].first+1 , ans[i].second+1);
	}
}
