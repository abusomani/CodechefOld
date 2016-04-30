#include <bits/stdc++.h>
#define M 10005
using namespace std;
int S[M];
int val[M];

int find(int x)
{
	if(S[x] < 0)
		return x;
	else
		return S[x] = find(S[x]);
}

void dounion(int x,int y)
{
	x = find(x);
	y = find(y);
	
	int val1 = val[x];	
	int val2 = val[y];
	
	if(val1 > val2)
		S[y] = x;
	else if(val2 > val1)
		S[x] = y;
}

int main()
{
	int t , N , Q , type , x , y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&N);
		memset(S , -1 , sizeof(S));
		for(int i = 1 ; i<=N ; i++)
		{
			scanf("%d",&val[i]);
		}
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d",&type);
			if(type)
			{
				scanf("%d",&x);
				printf("%d\n",find(x));
			}
			else
			{
				scanf("%d%d",&x,&y);
//				val[x] <-	value of xth dish	
				
				if(find(x) == find(y))
					printf("Invalid query!\n");
				else
					dounion(x,y);
			}
		}
	}
}
