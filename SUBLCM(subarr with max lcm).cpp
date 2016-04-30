/*
	question - biggest subarray whose LCM is equal to their product i.e. all those element doesn't have any common factor
	it can be solved by window method.  but here dp is used . we need to see one thing , when we are at i the ans can't 
	be more than ans[i-1]+1 and if a[i] has one comman factor after ans[i-1] starting position then it will be less
	that is why ans[i]  =  min(ans[i-1] + 1 , i - cal[i])           i-cal[i] represents part which has no common factor
*/

#include <bits/stdc++.h>
#define M 1000005
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N , a[M] , cal[M] , ans[M] , mark[M] , last_idx[M] , Ans; 			//	cal[i] denotes last idx  not a co_prime with a[i]
vector<int> prime;

void calculate()
{
	int t , prev;
	for (int i = 1; i <= N; ++i)
	{
		t = a[i];
		prev = 0;
		while(t > 1)
		{
			if(mark[t] != prev)
			{	
				cal[i] = max(cal[i] , last_idx[mark[t]]);
				last_idx[mark[t]] = i;
			}	
			prev = mark[t];
			t /= mark[t];
		}
	}
	
//	for(int i = 1 ; i<=N ; i++)
//		cout<<cal[i]<<"  ";
//	cout<<endl;
}


void sieve(int n)
{
	memset(mark , false , sizeof(mark));
	for (int i = 2; i < n; ++i)
	{
		if(mark[i] == 0)
		{
			for (int j = i; j < n; j+=i)
				mark[j] = i;
		}
	}
}

int main()
{
	sieve(M);
	int Cases;
	scanf("%d" , &Cases);
							
	while(Cases--)
	{
		memset(cal , 0 , sizeof(cal));
		memset(last_idx , 0 , sizeof(last_idx));
		
		scanf("%d" , &N);
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d" , &a[i]);
		}

		calculate();
		Ans = ans[1] = 1;

		for (int i = 2; i <= N; ++i)
		{
			ans[i] = min(ans[i-1] + 1 , i - cal[i]);	
			Ans = max(ans[i] , Ans);
		}

		if(Ans == 1)
			Ans = -1;
		printf("%d\n", Ans);
	}	
}
