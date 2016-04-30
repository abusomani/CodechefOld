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
ll abs(ll x)
{
	return (x>0)?x:-x;
}
/*
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
*/
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
#define MAX 100002
ll k , end;
ll avail(ll *a,ll i,ll *pos)
{
	ll sum = 0;
	ll j;
	for(j = k; j<end ; j++)
	{
		k=j;
		if( a[pos[j]] + a[i] <=0 )
		{
			a[pos[j]] = a[pos[j]] + a[i] ; 
			sum += abs(pos[j]-i)*a[i];
			break;
		}
		else
		{
			a[i] = a[i] + a[pos[j]];
			sum += abs(pos[j]-i)*(-a[pos[j]]);
			a[pos[j]] = 0;
		}
	}
	return sum;
} 
int main()
{
	ll t;
	ll	n , pos[MAX];
	ll a[MAX];
	ll sum;
	s(t);
	while(t--)
	{
		k = 0;
		sum =end= 0;
		sl(n);
		F(n)
		{
			sl(a[i]);
			if(a[i]<0)		pos[k++] = i;
		}
		end = k;
		k = 0;
		F(n)
		{
			if(a[i]>0)
			{
				sum += (avail(a,i,pos));
			}
		}
		pl(sum);
		nl;
	}

}
