#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int n,m,k,i,j;
cin>>n>>m>>k;
int a[n][m],col[m];
	for(int x=0;x<n;x++)
		{
		for(int y=0;y<m;y++)
			{if(x==0)
				col[y]=0;
			a[x][y]=0;
			}
		}
	for(int x=0;x<k;x++)
		{cin>>i>>j;
			col[j-1]++;
			a[i-1][j-1]=1;
		}
	std::sort(col,col+m);
	for()
return 0;
}
