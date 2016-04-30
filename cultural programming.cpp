#include<bits/stdc++.h>
using namespace std;
struct var
{int a,b;
};
int cmptr(const void * p1,const void * p2)
{return ((struct var *)p1)->b -((struct var *)p2)->b;
}
int main()
{ios_base::sync_with_stdio(false);
int n;
cin>>n;
var v[n];
int count=1,low,high,flag=1,maximum=-1;
	for(int i=0;i<n;i++)
	cin>>v[i].a>>v[i].b;
	qsort(v,n,sizeof(struct var),cmptr);
	low=v[n-1].a;
	high=v[n-1].b;
	for(int i=n-2;i>=0;i--)
		{
				if(v[i].b>=low)
				{count++;
				low=max(v[i].a,low);
				high=min(v[i].b,high);
				}
			
			else
				{
				if(count>maximum)
				maximum=count;
				low=v[i].b;
				high=v[i].a;	
				}
		}
	if(maximum>count)
	cout<<maximum;
	else
	cout<<count;
return 0;
} 
