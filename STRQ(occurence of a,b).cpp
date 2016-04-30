#include<bits/stdc++.h>
#include<stdio.h>
#define M 1000005
using namespace std;
#define gc getchar_unlocked
#define sfast(x) scanf(" %d",&x)		//	use fastIO for accepting

typedef unsigned long long ll;
int x,y;
ll store[M][4][4];
ll keep[4][M];
char str[M];
int val[100];
 
int main()
{
	char ch1,ch2;
	int q,f,l,i,j,k;
	ll precnt , sum;
	scanf("%s",str);
	int t = strlen(str);
	val[(int)'c'] = 0;
	val[(int)'h'] = 1;
	val[(int)'e'] = 2;
	val[(int)'f'] = 3;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			precnt = 0LL;
			if(i != j)
			{
				for(k=0;k<t;k++)
				{
					if(val[str[k]] == i)
						precnt++;
					if(val[str[k]] == j)
						store[k][i][j] = (ll)(store[k-1][i][j] + precnt);
					else
						if(k)	store[k][i][j] = store[k-1][i][j];
						else	store[k][i][j] = 0;
				}
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		k = 0;
		if(val[str[0]] == i)		keep[i][0] = 1LL;
		else						keep[i][0] = 0LL;
		for(int j=1;j<t;j++)
		{
			if(val[str[j]] == i)
	            keep[i][j] = keep[i][j-1] + 1LL;
		    else
		    	keep[i][j] = keep[i][j-1];
		}
	}
	
	sfast(q);
	while(q--)
	{
		scanf(" %c",&ch1);	
		scanf(" %c",&ch2);
		sfast(x);		sfast(y);
		x--;	y--;
		sum = 0;
		f = val[ch1];
		l = val[ch2];
		
		if(x)
			printf("%lld\n",(store[y][f][l] - store[x-1][f][l]) - (keep[l][y]-keep[l][x-1])*(keep[f][x-1]));
		else
			printf("%lld\n",store[y][f][l]);
	}
}  
