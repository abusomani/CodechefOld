/*
	question - given some point in co_ordinate we need to put our house such that total distance of this point 
	to all other points in minimised.   In 1D the median point has min distance to all other points
	same theory work here also , i.e. **we can take X and Y co_ordinate as independent** and solve then. 
*/

#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	int Cases;
	scanf("%d" , &Cases);
	int X[M] , Y[M] , N;

	while(Cases--)
	{
		scanf("%d" , &N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d %d" , &X[i] , &Y[i]);
		}
		sort(X , X+N);
		sort(Y , Y+N);
		
		if(N&1)					//	If N is odd there will be only one point as median in X and Y so total pos = 1*1 = 1
		{
			printf("1\n");			
		}
		else					//	If N is even then 2 median will be there and any point b/w these points will give same
		{						//	distance from all points so total condidates will be a and b  and ans will be a*b
		
			int a = X[N/2] - X[N/2-1] + 1;
			int b = Y[N/2] - Y[N/2-1] + 1;
			printf("%lld\n" , (ll)a*b);			//	we can choose a pts from X , b pts from Y so total possibiltity = a*b
		}
	}	
}

