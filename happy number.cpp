//	uva 10591

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long n,rem,sum=0,count=0;
	int a,b;
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>n;
		int keep = n;
//		if(i==1)	{ 		cout<<i<<" "<<(1)<<endl;	continue;	 }
		while(1)
		{
		    sum=0;
		    while(n>0)
			{	  rem=n%10;	       sum+=rem*rem;    	n=n/10;   }
		    n=sum;   sum=0;   
		    if(n==1)
			{   printf("Case #%d: %d is a Happy number.",j,keep);     		 break;    }
			if(n==2 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9 )
			{   printf("Case #%d: %d is an Unhappy number.",j,keep);        break;    }
		}
		cout<<endl;
	}
}
