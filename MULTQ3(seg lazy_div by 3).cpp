#include <bits/stdc++.h>
#define M 300002
#define MOD 1000000007
using namespace std;
typedef long long ll;

struct val
{
	int rem[3];
	int p;
	val()
	{
		p = 0;
	}
	val(int a, int b, int c)
	{
		val();
		rem[0] = a;		rem[1] = b;		rem[2] = c;	
	}
};
val st[M];

void rotate(val& v)
{	
	int tmp = v.rem[2];
	v.rem[2] = v.rem[1];
	v.rem[1] = v.rem[0];
	v.rem[0] = tmp;
}

val merge(val a , val b , int p = 0)
{
	val tmp;
	tmp.p = p;
	for (int i = 0; i < 3; ++i)
		tmp.rem[i] = a.rem[i] + b.rem[i];
	for (int i = 0; i < p; ++i)
		rotate(tmp);
	return tmp; 
}

void build(int lo , int hi , int idx)
{
	if(lo == hi)
	{
		st[idx] = val(1,0,0);
		st[idx].p = 0;
		return;
	}
	int mid = (lo+hi)>>1;
	build(lo , mid , 2*idx+1);
	build(mid+1 , hi , 2*idx+2);

	st[idx] = merge(st[2*idx+1] , st[2*idx+2]);
}

void update(int lo , int hi , int u , int v , int idx)
{
	if(u>hi || v<lo)
		return;

	if(u<=lo && v>=hi)
	{
		rotate(st[idx]);
		st[idx].p = (st[idx].p + 1)%3;
		return;
	}

	int mid = (lo + hi)>>1;
	update(lo , mid , u , v , 2*idx+1);
	update(mid+1 , hi , u , v , 2*idx+2);
	st[idx] = merge(st[2*idx+1] , st[2*idx+2] , st[idx].p);
}

int query(int lo , int hi , int u , int v , int idx , int p)
{
	if(u>hi || v<lo)
		return 0;
	if(u<=lo && v>=hi)
		return st[idx].rem[(3-p)%3];

	int mid = (lo + hi)>>1;
	p = (st[idx].p + p) %3;
	return (query(lo , mid , u , v , 2*idx+1 , p) + query(mid+1 , hi , u , v , 2*idx+2 , p));
}

int main()
{
//	freopen("E://pp.txt" , "r" , stdin);
	int type , N , Q , l , r;
	scanf("%d %d" ,&N ,&Q);
	build(0,N-1,0);

	while(Q--)
	{
		scanf("%d %d %d" , &type, &l, &r);
		if(type == 0)
		{
			update(0,N-1,l,r,0);
		}
		else
		{
			printf("%d\n", query(0,N-1,l,r,0,0));
		}
	}
}			
