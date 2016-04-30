#include<bits/stdc++.h>
using namespace std;
struct var
{int a,b;
};
int cmptr(const void * p1,const void * p2)
{return ((struct var *)p1)->a -((struct var *)p2)->a;
}
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int n,count=1,low,high,flag=0;
	cin>>n;
	var v[n];
	for(int i=0;i<n;i++)
	cin>>v[i].a>>v[i].b;
	qsort(v,n,sizeof(struct var),cmptr);
	for(int i=1;i<=n-1;i++)
		{if(flag)
			{if(v[i].a>=low&&v[i].a<=high)
				{low=v[i].a;
				high=min(high,v[i].b);
				}
			else
				{count++;
				flag=0;
				}
			}
		else if(v[i].a>v[i-1].b)
			count++;
		else
			{low=v[i].a;
			high=min(v[i-1].b,v[i].b);
			flag=1;
			}
		}
	cout<<count<<endl;
	}
}
