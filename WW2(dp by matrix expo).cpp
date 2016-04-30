/*
	In this Que we have recurrence reln as Ans[i][j] = Ans[i-1][j-1] + Ans[i-1][j+1] + (i%2==0)?0:Ans[i-1][j];
	As n is so large we can't solve by looping we can use matrix exponentation	,  here we'll get even and odd matrix
	and get their N/2 power , and add all of them .
	as ans depends on j-1 , j , j+1 for each i , we will make i,i-1 ; i,i+1 as 1 in even   and  i,i-1 ; i,i+1 ; i,i  as 1 in odd
	(line 82-89)   (chk solution of recurrence by matrix exponentiation online for understanding above initailisation :)
*/

#include <bits/stdc++.h>
#define MAX 30
#define MOD 1000000007
#define rep(i,a)	for(i=0 ; i<a ; i++)
using namespace std;
typedef long long ll;
int M;

struct Matrix
{
	ll A[MAX][MAX];
	Matrix()
	{
		int i , j;
		rep(i,M)	rep(j,M)
		A[i][j] = 0;
	}
	Matrix operator*(Matrix a)
	{
		int i , j , k;
		Matrix tmp;
		rep(i,M)	rep(j,M)	rep(k,M)
		{
			tmp.A[i][j] += (ll)(A[i][k] * a.A[k][j]);
			if(tmp.A[i][j] >= MOD)
				tmp.A[i][j] %= MOD;
		}
		return tmp;
	}
	void identity()
	{
		int i , j;
		rep(i,M)	
		A[i][i] = 1;
	}
	void show()
	{
		int i , j;
		rep(i,M)	
		{
			rep(j,M)
			{	 cout<<A[i][j]<<"  ";	}
			cout<<endl;
		}
	}
};

Matrix pow(Matrix base , int exp)
{
	Matrix res;
	res.identity();
	while(exp > 0)
	{
		if(exp & 1)
			res = res * base;
		base = base * base;
		exp >>= 1;
	}
	return res;
}

int main()
{
	int Cases;
	int i , j;
	scanf("%d" , &Cases);

	int N;
	while(Cases--)
	{
		scanf("%d %d" , &N , &M);

		Matrix even , odd;
		rep(i,M)	rep(j,M)
		{
			odd.A[i][i] = 1;
			if(i-1 >= 0)
				even.A[i][i-1] = odd.A[i][i-1] = 1;
			if(i+1 < M)
				even.A[i][i+1] = odd.A[i][i+1] = 1;
		}

		N--;
		Matrix base = even*odd;
		base = pow(base , N/2);
		if(N%2)
			base = base*even;

		ll ans = 0LL;
		rep(i,M)	rep(j,M)
		{
			ans += base.A[i][j];
			if(ans >= MOD)
				ans %= MOD;
		}
		printf("%lld\n" , ans);
	}	
}
