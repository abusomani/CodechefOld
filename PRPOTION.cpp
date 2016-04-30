#include<stdio.h>
#include<string.h>
#include<math.h>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld",x)
#define gap	printf(" ")
#define nl   printf("\n")
#define chk   printf("hello    ")
#define F(x)	for(int i=0;i<x;i++)
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
typedef long long ll;
typedef unsigned long long ull;

int max(int a,int b)
{
	return (a>b)?a:b;
}
int max(int a,int b,int c)
{
	return max(a,max(b,c));
}

#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

//void print(int *a,int n)
//{	nl;	F(n)	{	p(a[i]);	space;	}	nl;		}

/*
#include<time.h>
#define timestart int tstart = clock()
#define printtime (double)(clock()-tstart)/CLOCKS_PER_SEC
*/
/*
#define gc getchar_unlocked
void sfast(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
*/
int main()
{
	int t,i;
	s(t);
	int r,g,b,m,x , y , z,big;
	int mx , my , mz;
	int a[3];
	while(t--)
	{
		mx = my = mz = -1;
		s(r);	s(g);	s(b);	s(m);
		for(i=0;i<r;i++)
		{
			s(x);
			mx = max(x,mx);
		}
		for(i=0;i<g;i++)
		{
			s(y);
			my = max(y,my);
		}
		for(i=0;i<b;i++)
		{
			s(z);
			mz = max(z,mz);
		}
		a[0] = mx;	 a[1] = my;	   a[2] = mz;
		for(i=0;i<m;i++)
		{
			sort(a,a+3);
			a[2] = a[2]/2;
		}
		sort(a,a+3);
		p(a[2]);
		nl;
	}

}
