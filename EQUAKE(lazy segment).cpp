//	it worked in time limit with help of fast i/o

#include <bits/stdc++.h>
#define M 800002											//		|			|	-------------
#define MOD 1000000007										//		|			|		  |
using namespace std;										//		|			|		  |
typedef long long ll;										//		|			|		  |
															//		|			|		  |
struct node													//		|___________|		  |
{															//
	int val[12];
	int p;
};

node st[2097152];
int N , a[800001];

int rotate(int x , int pos)
{
	if (x < 10) return x;
	if (x < 100) return (pos & 1) ? (x % 10 * 10 + x / 10) : x;
	if (x < 1000)
	{
		if (pos % 3 == 0) return x;
		if (pos % 3 == 1) return x % 100 * 10 + x / 100;
		return x % 10 * 100 + x / 10;
	}
	if (pos % 4 == 0) return x;
	if (pos % 4 == 1) return x % 1000 * 10 + x / 1000;
	if (pos % 4 == 2) return x % 100 * 100 + x / 100;
	return x % 10 * 1000 + x / 10;
}

void rotate_arr(int arr[] , int pos) 
{
	int i , k = 0 ;
	pos = pos%12;
	if(!pos)	return ;
	vector<int> v;
	for (i = 0 ; i<pos ; ++i)
		v.push_back(arr[i]);
		
	for (i = 0 ; i<12-pos ; ++i)
		arr[i] = arr[i+pos];

	while(pos--)
		arr[i++] = v[k++];
}

node merge(node a , node b , int p = 0)
{
	node tmp;
	tmp.p = p;
	for(int i = 0 ; i<12 ; i++)
		tmp.val[i] = max(a.val[(i+p)%12] , b.val[(i+p)%12]);
	return tmp;
}

void build(int lo , int hi , int idx)
{
	if(lo == hi)
	{
		for(int i = 0 ; i<12 ; i++)
			st[idx].val[i] = rotate(a[lo] , i);
		st[idx].p = 0;
		return;
	}
	int mid = (lo + hi)>>1;
	build(lo , mid , 2*idx + 1);
	build(mid+1 , hi , 2*idx + 2);
	
	st[idx] = merge(st[2*idx+1] , st[2*idx+2]);
}

void update(int lo , int hi , int u , int v , int F , int idx)
{
	if(u>hi or v<lo)
		return;
	if(u<=lo and v>=hi)
	{	
		rotate_arr(st[idx].val , F);
		st[idx].p = (st[idx].p + F) %12;
//		if(lo != hi)
//		{
//			st[2*idx+1].p = (st[2*idx+1].p + F) %12;
//			st[2*idx+2].p = (st[2*idx+2].p + F) %12;
//		}
		return;										// main optimise step we won't go below , we'll store pending rotation in p
	}
	int mid = (lo + hi)>>1;
	update(lo , mid , u , v , F , 2*idx+1);
	update(mid+1 , hi , u , v , F , 2*idx+2);
	
	st[idx] = merge(st[2*idx+1] , st[2*idx+2] , st[idx].p);
}

int query(int lo , int hi , int u , int v , int idx , int p)
{
	if(u>hi or v<lo)
		return -1;

	if(u<=lo and v>=hi)
	{
		return st[idx].val[(p)%12];
	}
	int mid = (lo + hi)>>1;
	p = (p + st[idx].p)%12;
	return max( query(lo , mid , u , v , 2*idx+1 , p) , query(mid+1 , hi , u , v , 2*idx+2 , p) );
}

void print()
{
	for(int i = 0 ; i<2*N-1 ; i++)
	{
		cout<<i<<"  :  ";
		for(int j = 0 ; j<12 ; j++)
		{
			cout<<st[i].val[j]<<",";
		}
		cout<<" ("<<st[i].p<<")"<<endl;
	}
	cout<<endl;
}

int main()
{
//	freopen("E://pp.txt" , "r" , stdin);
	
	int Q , type , L , R , F;
	scanf("%d" , &N);
	
	for (int i = 0; i < N; ++i)
		scanf("%d" , &a[i]);	
	
	build(0,N-1,0);
	scanf("%d" , &Q);
	while(Q--)
	{
		scanf("%d" , &type);
		switch(type)
		{
			case 0:
				scanf("%d %d %d" , &L , &R , &F);
				update(0,N-1,L,R,F%12,0);
				break;
			case 1:
				scanf("%d %d" , &L , &R);
				printf("%d\n" ,query(0,N-1,L,R,0,0));
				break;
		}
	}
}
