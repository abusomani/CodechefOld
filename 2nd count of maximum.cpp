#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
scanf("%d",&t);
while(t--)
	{int n,x,pos,a[10001]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		{scanf("%d",&x);
		a[x]=a[x]+1;
		}
	x=0;
	for(int i=0;i<10001;i++)
		{if(a[i]>x)
			{x=a[i];
			pos=i;
			}
		}
	printf("%d %d\n",pos,x);
	}
}
