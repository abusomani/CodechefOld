#include<iostream>
using namespace std;
int partition(int a[],int beg,int end)
	{int p=beg,pivot=a[beg],loc;
	for(loc=beg+1;loc<=end;loc++)
		{if(pivot>a[loc])
			{a[p]=a[loc];
			a[loc]=a[p+1];
			a[p+1]=pivot;
			p=p+1;
			}
		}
		return p;
	}
void Quicksort(int a[],int beg,int end)
	{if(beg<end)
		{int p=partition(a,beg,end);
		Quicksort(a,beg,p-1);
		Quicksort(a,p+1,end);
		}
	}
int main()
{int t,m,n;
cin>>t;
while(t--)
	{cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	Quicksort(a,0,n-1);
	int max=a[n-1],sum=0;
	for(int i=0;i<n;i++)
		sum+=max-a[i];
	if(sum==m)
	cout<<"Yes"<<endl;
	else if(sum>m)
	cout<<"No"<<endl;
	else if(sum<m)
	{int x=m-sum;
	x=x%n;
	if(x==0)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
	}
}
return 0;
}
