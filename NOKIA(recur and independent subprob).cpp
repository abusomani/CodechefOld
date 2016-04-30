/*
	the main part of the problem is - we are asked to find minimum unused wire i.e. max_used_length <= M
 	so if minL[N] is minimum used len and maxL[N] is maximum used len for N position then we can achieve  
	all lengths  ->  between minL[N] and maxL[N] <-  so if minL[N] is <= M , ans = 0   else  ans = M - maxL[N]
	
	and minL of big N depends on smaller N 's minL     and  maxL of big N depends on smaller N 's maxL
*/

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int minL[51] , maxL[51];

void pre()
{
	minL[0] = maxL[0] = 0;
	for(int i = 1 ; i<50 ; i++)
	{
		int k = i/2;											//	divide position is i/2 for minimum answer
		minL[i] = minL[i-k-1] + minL[k] + (i+1);	 			//	i+1 for first position
		maxL[i] = maxL[i-1]	+ (i+1);							//	max_len achieve when we put sequentially
	}
}
//	recursive proc - 
//int solve(int lf , int rt , int remain)
//{
//	cout<<lf<<" : "<<rt<<" : "<<remain<<endl;
//	if(rt-lf >= remain-1)		return INT_MAX;
//	if(remain < 0)				return INT_MAX;
//	if(rt-lf == 2)				return (remain-2)<0 ? INT_MAX : remain-2;
//	if(rt-lf == 1)				return 0;
//				
//	ans = INT_MAX;
//	for (int i = lf + 1 ; i < rt ; ++i)
//	{
//		r  = remain - (rt-lf);
//		r1 = solve(lf , i , r);
//		r2 = solve(i , rt , r1);
//		ans = min(ans , r2);
//	}
//	return ans;
//}

int main()
{
	int N , M , ans;
	int Cases;
	scanf("%d" , &Cases);
	pre();
	while(Cases--)
	{
		scanf("%d %d" , &N , &M);
		if(M < minL[N])      	 ans = -1;
    	else if(M <= maxL[N])	 ans = 0;
    	else                	 ans = M-maxL[N];
  
		printf("%d\n", ans);
	}	
}
