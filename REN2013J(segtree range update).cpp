#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;

int a[M] , st[M];

void build(int lo , int hi , int idx)
{
	if(lo == hi)
	{
		st[idx] = a[lo];
		return ;
	}
	int mid = (lo + hi)>>1;
	build(lo , mid , 2*idx);
	build(mid + 1 , hi , 2*idx + 1);

	st[idx] = st[2*idx] + st[2*idx+1];
}

void update(int lo , int hi , int u , int v , int idx)
{
	if(u>hi || v<lo)
		return;
	int mid = (lo + hi)>>1;
	
	if(st[idx] == 0)
		return;
	
	if(lo == hi)
	{
		st[idx] /= 2;
		return;
	}
	update(lo , mid , u , v , 2*idx);
	update(mid + 1 , hi , u , v , 2*idx + 1);
	st[idx] = st[2*idx] + st[2*idx+1];
}

int query(int lo , int hi , int u , int v , int idx)
{
	if(u>hi || v<lo)
		return 0;
	if(u<=lo && v>=hi)
		return st[idx];

	int mid = (lo + hi)>>1;
	return query(lo , mid , u , v , 2*idx) + query(mid+1 , hi , u , v , 2*idx+1);
}

int main()
{
	int N , Q , type , l , r;
	scanf("%d" ,&N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d" ,&a[i]);
	}
	build(1,N,1);
	
	scanf("%d" ,&Q);
	while(Q--)
	{
		scanf("%d %d %d" , &type, &l, &r);
		if(type == 1)
		{
			update(1,N,l,r,1);
		}
		else
		{
			printf("%d\n", query(1,N,l,r,1));
		}
//		for(int i = 0 ; i<2*N ; i++)	cout<<st[i]<<" ";
//		cout<<endl;
	}
}			
