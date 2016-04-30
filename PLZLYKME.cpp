#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,flag=0;
	long long c,d,l,s,k;
	cin>>t;
	while(t--)
	{
		flag=0;
		cin>>l>>d>>s>>c;
	    for(int i=1;i<=d;i++)
	    {
	    	
	    	if((l-s)<=0)
	    	{  
			   cout<<"ALIVE AND KICKING\n";  flag=1;
	    	   break;
	        }
	        s=s*(1+c);
	    }
		if(flag==0)
		cout<<"DEAD AND ROTTING\n";
	}
}
