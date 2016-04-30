/*
	the tricky part of the problem was memory first we have to use as less memory as we can and second all arrays should 
	be declare outiside the main ( got ~10 SigSegv because of declaring all array inside the main )
*/

#include <bits/stdc++.h>
#define M 1000001
#define MOD 1000000009
using namespace std;
typedef long long ll;
int a[M] , lastidx[8*M] , Ans[M] , N , lasta , ca;
int off = 4000000;	 

void solve()
{
	scanf("%d" ,&N);
	scanf("%d" ,&lasta);
	for (int i = 0; i < N-1; ++i)
	{
		scanf("%d" ,&ca);
		a[i] = ca - lasta + off;
		lasta = ca;
	}
	if(N == 1)
	{
		printf("1\n");
		return;
	}

	N--;
	Ans[0] = 1;
	lastidx[a[0]] = 0;
	
	for (int i = 1; i < N; ++i)
	{
		if(lastidx[a[i]] == -1)
			Ans[i] = 2*Ans[i-1] + 1;
		else 
			Ans[i] = 2*Ans[i-1] - Ans[lastidx[a[i]]-1];
			
		lastidx[a[i]] = i;
		
		while(Ans[i] < 0)			Ans[i] += MOD;
		while(Ans[i] >= MOD)		Ans[i] -= MOD;
	}
	for (int i = 0; i < N; ++i)
		lastidx[a[i]] = -1;
		
	printf("%d\n" , Ans[N-1]);
}

int main()
{
//	freopen("E://to.txt" , "r" , stdin);
 
	int Cases;
	scanf("%d" , &Cases);
	memset(lastidx , -1 , sizeof(lastidx));	
	while(Cases--)
	{
		solve();	
	}	
} 
