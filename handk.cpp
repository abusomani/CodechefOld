#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	long long  sum=0,n,i,k;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		if(n%2==1)   { k=n/2-1; sum=pow(2,k+3)-2; }   else  { k=(n-1)/2-1;   sum=pow(2,n/2)+pow(2,k+3)-2;   }
		cout<<(sum)% 1000000007<<endl;
	}
	
}
