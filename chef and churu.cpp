#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void sumoffunction(int a[],ll f[],int L[],int R[],int N)
{
	for(int i=0;i<N;i++)
		{ll sum=0;
		for(int j=L[i]-1;j<R[i];j++)
		sum+=a[j];
		f[i]=sum;
		}
	
}
void swap(int a[],int x,int y)
	{a[x-1]=y;
	}
int main()
{
int N,q,type,m,n;
int a[100005];
scanf("%d",&N);
	for(int i=0;i<N;i++)	
	cin>>a[i];
	int L[N],R[N];
	for(int i=0;i<N;i++)
		cin>>L[i]>>R[i];
	ll f[N];
	sumoffunction(a,f,L,R,N);
	scanf("%d",&q);
	while(q--)
	{ll sum=0;
	cin>>type>>m>>n;
		if(type==1)
			{
			swap(a,m,n);
			sumoffunction(a,f,L,R,N);
			}
		else if(type==2)
			{for(int i=m-1;i<n;i++)
			sum+=f[i];	
			cout<<sum<<endl;
			}
		
	}
return 0;
}
