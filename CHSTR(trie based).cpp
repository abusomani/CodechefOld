#include <bits/stdc++.h>
#define M 26
#define MAX 5010
#define MOD 1000000007
#define to(x) (int)x - (int)'a'
using namespace std;
typedef long long ll;
 
ll ans[MAX];
int maxf , pre[MAX];
int ncr[MAX][MAX];
struct trie
{
	int freq;
	trie* next[M];
	trie()
	{
		freq = 1;
		memset(next , 0 , sizeof(next));
	}
};
 
trie* root;
 
void insert_in_trie(char str[])
{
	trie* t = root;
	int l = strlen(str) , x;
	for(int i = 0 ; i<l ; i++)
	{
		x = to(str[i]);
		if(t->next[x] == NULL)
			t->next[x] = new trie();
		else
			t->next[x]->freq++;
		t = t->next[x];
	}
}
 
void insert(char str[])
{
	int l = strlen(str);
	for(int i = 0 ; i<l ; i++)
	{
		insert_in_trie(str+i);
	}
}
 
void bfs()
{
	trie* t = root;
	queue<trie*> q;
	q.push(t);
	
	maxf = 0;
	for(int i = 0 ; i<M ; i++)
		if(t->next[i])
			maxf = max(maxf , t->next[i]->freq);
	
	while(!q.empty())
	{
		t = q.front();		q.pop();
		for(int i = 0 ; i<M ; i++)
		{
			if(t->next[i])
			{
				ans[t->next[i]->freq]++;
				q.push(t->next[i]);
			}
		}
	}
}
 
int main()
{
//	freopen("E://t1.txt" , "r" , stdin);
//	freopen("E://txx.txt" , "w" , stdout);
	
	int Case;
	scanf("%d" , &Case);
	char str[5010];
	int l,q,K;
	
	for(int i=1 ; i<MAX ; i++)
	{  
		ncr[i][1]=i;  
	    ncr[i][i]=1;
    }
	for(int i=2 ; i<MAX ; i++)
	{
		for(int j=2 ; j<i ; j++)
		{
			ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]) %MOD;
		}
	}
	
	ll Ans = 0LL;
	while(Case--)
	{
		root = new trie();
		memset(ans , 0 , sizeof(ans));
		scanf("%d %d" , &l , &q);
		scanf("%s" , str);
		insert(str);
		bfs();
		
//		for(int i = 1 ; i<=maxf ; i++)
//			cout<<i<<" : "<<ans[i]<<endl;
		
		for(K = 1 ; K<=maxf ; K++)
		{
			Ans = ((ll)ans[maxf]*ncr[maxf][K]) % MOD;
			for(int j = maxf-1 ; j>=K ; j--)
			{
				Ans = (Ans + (ll)ans[j]*ncr[j][K]) % MOD;
			}
			pre[K] = Ans;
		}
		
		while(q--)
		{
			scanf("%d" ,&K);
			if(K > maxf)
				printf("0\n");
			else
			{
				printf("%d\n", pre[K]);
			}
		}
	}
} 
