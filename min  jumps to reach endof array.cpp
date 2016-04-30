#include<bits/stdc++.h>
using namespace std;
#define M 100
#define MAX 2147483647
int sol[M];
int par[M];
int stop = 100;
int jump(int arr[],int i,int dest)
{
	int temp;
	stop--;
	if(!stop)		exit(0);
	if(i==dest)
		return 0;
	if(sol[i]!=MAX)
		return sol[i];
	if(arr[i]==0)
		return MAX;
	for(int k=1;k<=arr[i] && i+k<=dest;k++)
	{
		temp = jump(arr,i+k,dest);
		if(temp!=MAX)
		{
			sol[i] = 1 + min(sol[i],temp);
		//	cout<<i<<" : "<<i+k<<endl;
		}
	}	
	return sol[i];
}
int  main()
{
	int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	int n = sizeof(arr)/sizeof(int);
	for(int i=0;i<M;i++)
		sol[i] = MAX;
//	for(int i=0;i<n;i++)
//		cout<<par[i]<<"  ";
	cout<<"ANS is  "<<jump(arr,0,n-1);	
}
