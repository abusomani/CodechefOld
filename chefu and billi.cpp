#include<bits/stdc++.h>
using namespace std;
int steps(int N,int a,int b,int sum)
{//static int sum=0;
if(N-a<=0)
		{sum+=N;
		return sum;
		}
else
	{
		sum+=(a+b);
		N=N-a+b;
		steps(N,a,b,sum);
	}


	
}
int main()
{int t;
cin>>t;
while(t--)
	{
	
	int n,a,b,d,min=INT_MAX,pos=0;
	cin>>n;
	int A[n],B[n],C[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];
	cin>>d;
	for(int i=0;i<n;i++)
		{
			C[i]=steps(d,A[i],B[i],0);
			cout<<C[i]<<"  ";
			if(C[i]<min)
				{
					min=C[i];
					pos=i+1;
				}
		}
	cout<<pos<<endl;
	
	}
	
}
