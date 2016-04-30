/*
	the key point here is we will not generate all possible patterns , we will get probabilty of occurence of each color 
	at every index then at the end , we will multiply the probability with the respective color to get the expected color then 
	add them all ()
	for getting probability we'll use DP   souce -> 	http://discuss.codechef.com/problems/LEPAINT
*/


#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main()
{
	int Cases , N , c , K , l , r;
	cin>>Cases;
	double dp[52][52][102];	//	dp[i][j][k] -> prob. of getting color k at index j in ith turn

	while(Cases--)
	{
		cin>>N>>c>>K;
		double rt = (1.0 / (2.0*c));
		memset(dp , 0 , sizeof(dp));
		
		for(int j = 1 ; j<=N ; j++)
				dp[0][j][1] = 1.0;
		
		for(int i = 1 ; i<=K ; i++)
		{
			cin>>l>>r;
			for(int j = 1 ; j<=N ; j++)
			{
				for(int k = 0 ; k<c ; k++)
				{
					if(j>=l && j<=r)
					{
						for(int m = 0 ; m<c ; m++)						//	if it is choosen in subset then trying all color
							dp[i][j][(m*k)%c] += (dp[i-1][j][k]*rt);	//	rt = 1/2c because 1/2 for choosing, 1/c for color
								
						dp[i][j][k] += 0.5*dp[i-1][j][k];				//	if it is not choosen
					}
					else
						dp[i][j][k] += dp[i-1][j][k];					//	outside query so p will remain same 	
				}
			}		
		}
		
		double ans = 0.0;
		for(int i = 1 ; i<=N ; i++)
		{
			for(int j = 0 ; j<c ; j++)
			{
				ans += j*dp[K][i][j];						//	dp[K][i][j]	- p of jth color at index i after K turn
			}
		}
		
		printf("%.9f\n",ans);
	}
}
