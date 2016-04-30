#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int binarysearch(int AR[], int N, int VAL)
{
	int Mid,Lbound=0,Ubound=N-1;

	while(Lbound<=Ubound)
	{
		Mid=(Lbound+Ubound)/2;
		if(VAL>AR[Mid])
			Lbound=Mid+1;
		else if(VAL<AR[Mid])
			Ubound=Mid-1;
		else
			return Mid;
	}

	return 0;
}
int main()
{ios_base::sync_with_stdio(false);
int t;
scanf("%d",&t);
while(t--)
	{int n,k,a[102];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&k);
	int t=a[k-1];
	sort(a,a+n);
	int pos=binarysearch(a,n,t);
	cout<<pos+1<<endl;
	}
return 0;
}
