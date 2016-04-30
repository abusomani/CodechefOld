#include<iostream>
#include<cmath>
using namespace std;
inline bool prime(long int p)
{
	if(p==1) return 0;
	int i;
	for(i=2;i<=(int)sqrt(p);i++)
{	if(p%i==0)  return 0;  }return 1;
}
inline long gcd(long a, long b)
{
	  long r;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main()
{
	short t;
	long int a,b,count=0,i,j,k,p;
	cin>>t;
	for(i=0;i<t;i++)
	{
		count=0;
	    cin>>a>>b;
		for(k=1;k<=a;k++)
		{
			for(j=1;j<=b;j++)
			{
				p=gcd(k,j);
				if(prime(p)) {
				count++;}
			}
		}
		cout<<count<<endl;	
	}
}
