#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;
string str;

struct val
{
	int sum;
	int pre[3];													//	pre[i] -> cnt of those prefix giving i when mod by 3
	int suf[3];													//	suf[i] -> cnt of those suffix giving is when mod by 3
	ll ans;
	val()
	{
		memset(pre , 0 , sizeof pre);
		memset(suf , 0 , sizeof suf);
		ans = sum = 0;
	}
};
val st[M] , dummy;

val newval(int n)
{
	n = n%3;
	val v;
	v.sum = n;
	v.ans = (n == 0);
	v.pre[n] = 1;
	v.suf[n] = 1;
	return v;
}

val merge(val a , val b)
{
	val v;
	v.ans = (a.ans + b.ans);								//	direct adding pairs
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if((i+j)%3 == 0)
			{
				v.ans = v.ans + (ll)a.suf[i]*b.pre[j];		//	the pre & suff which make substr divisible by 3 in mid 
			}
		}
	}
	for (int i = 0; i < 3; ++i)
	{	
		v.pre[i] = a.pre[i] + b.pre[(6-a.sum+i)%3];			//	pre[i] will be a.pre[i] and   those pre of b which when add
		v.suf[i] = b.suf[i] + a.suf[(6-b.sum+i)%3];			//	to a.sum gives number divisible by 3   same for suff
 	}
 	v.sum = (a.sum + b.sum)%3;
 	return v;
}

void build(int lo , int hi , int idx)
{
	if(lo == hi)
	{
		st[idx] = newval((int)str[lo] - '0');
		return;
	}
	int mid = (lo+hi)>>1;
	build(lo , mid , 2*idx+1);
	build(mid+1 , hi , 2*idx+2);

	st[idx] = merge(st[2*idx+1] , st[2*idx+2]);
}

void update(int lo , int hi , int pos , int newvalue , int idx)
{
	if(pos>hi || pos<lo || lo>hi)
		return;

	if(lo == hi)
	{
		st[idx] = newval(newvalue);
	}

	int mid = (lo + hi)>>1;
	if(lo != hi)
	{
		update(lo , mid , pos , newvalue , 2*idx+1);
		update(mid+1 , hi , pos , newvalue , 2*idx+2);
		st[idx] = merge(st[2*idx+1] , st[2*idx+2]);
	}
}

val query(int lo , int hi , int u , int v , int idx)
{
	if(u>hi || v<lo || lo>hi)
		return dummy; 
	if(u<=lo && v>=hi)
		return st[idx];

	int mid = (lo + hi)>>1;
	return merge(query(lo , mid , u , v , 2*idx+1) , query(mid+1 , hi , u , v , 2*idx+2));
}

int main()
{
	int N , Q , type , X , Y;
	scanf("%d %d" , &N , &Q);
	cin>>str;
	build(0,N-1,0);
	while(Q--)
	{
		scanf("%d %d %d", &type , &X , &Y);
		if(type == 1)
		{
			update(0,N-1,X-1,Y,0);
		}
		else
		{
			printf("%lld\n" , query(0,N-1,X-1,Y-1,0).ans);
		}
		
//	for(int i = 0 ; i<2*N ; i++)
//		cout<<st[i].ans<<"  "<<st[i].sum<<"  "<<st[i].pre[0]<<"  "<<st[i].suf[0]<<endl;
	}
}
