#include<iostream>
using namespace std;
int main()
{
	long long  t,n,sum,sumr;
	cin>>t;
	while(t--)
	{
		sum=0;   sumr=0;
		cin>>n;
		sum=n*n;
		n--;
		sum += (n*(n+1)*(2*n+1)/6 + n*(n+1)/2)/2;
		if(n>3){
		n=n-2;
		if(n%2==0)
		{
			n/=2;
			sumr = 2*n*(n+1)*(2*n+1)/3 +  n*(n+1);
		}
		else
		{    n/=2;
		     sumr=n+2*n*(n+1)+2*n*(n+1)*(2*n+1)/3+1;
		     n++;
		     sumr+=n*n;
		}
	    sumr/=2;
	    sum+=sumr;}
	    cout<<sum<<endl;	
	}
	
}
