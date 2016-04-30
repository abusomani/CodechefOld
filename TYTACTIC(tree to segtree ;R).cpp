/*
			      1(1)				Q -> A superiority tree will be given to u then u hav to update any vertx or tell the sum of that subtree
			 /     |     \			i.e. if Query is 4 then we should tell val(4)+val(5)+val(9)+val(7)
	   3(2)       4(4)    6(8)    			so for this we will conert this tree to seg tree query tree   by mapping
		/		 /	\		\				
	 2(3)    5(5)   9(6)     8(9)		for that we will do dfs in this tree(in time in bracket)   and calc in and out time for
	    			 /		 \			every vrtx , now every Query will change to vertx's 'in to out time Range'	where 
        		    7(7)     10(10)		every value is stored in its in time index
        		    
    for ex in abve tree we will store val[i] in ft[in[i]]  ,  and when query "Q a" will be given we will query for 
    Range - in[a] to out[a]
*/

#include <bits/stdc++.h>
#define M 100005
#define nxt(x)  ( x & (-x) )
using namespace std;
typedef long long ll;

int T = 1 , N;
bool visit[M];
vector<int> g[M];
int in[M] , out[M] , val[M];
int ft[2*M];

void update(int pos , int d)
{
	for(int i = pos ; i<=N ; i += nxt(i))
		ft[i] += d;
}
int read(int pos)
{
	int sum = 0;
	for(int i = pos ; i>=1 ; i -= nxt(i))
		sum += ft[i];
	return sum;
}
int readRange(int a , int b)
{
	return read(b) - read(a-1);
}
void show()
{
	for(int i = 1 ; i<=N ; i++)
		cout<<i<<" : "<<ft[i]<<endl;
}

void dfs(int u)
{
	int v;
	visit[u] = 1;
	in[u] = T++;
	for (int i = 0; i < g[u].size(); ++i)
	{
		v = g[u][i];
		if(!visit[v])
			dfs(v);
	}
	out[u] = T;
}

int main()
{
	int Q , a , b;
	char type;
	scanf("%d %d" , &N , &Q);
	
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d" , &val[i]);
	}
	for (int i = 1; i < N; ++i)
	{
		scanf("%d %d" , &a , &b); 
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	for (int i = 1; i <= N; ++i)
	{
		update(in[i] , val[i]);
	}
//	show();
	while(Q--)
	{
		scanf(" %c" , &type);
		switch(type)
		{
			case 'U':
				scanf("%d %d" , &a , &b);
				update(in[a] , b - val[a]);
				val[a] = b;
				break;
			case 'Q':
				scanf("%d" , &a);
				printf("%d\n" , readRange(in[a] , out[a]-1));
				break;
		}
	}
}
