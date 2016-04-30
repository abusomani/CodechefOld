#include<iostream>
#include<string.h>
using namespace std;
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
    long a,num2,t,i;
	char b[300];
	cout<<sizeof(int)<<endl;
	cin>>t;
	while(t--)
	{
	    num2=0;
		cin>>a;
		cin>>b;
		if(a==0  &&  b[0]=='0')   cout<<"0\n";
		else if(a==0  ||  b[0]=='0')  
		{
			if(a==0)   {   for(i=0;b[i];i++)   cout<<b[i];    cout<<endl;   }
			else  cout<<a<<endl;
		}
		else
		{
		for(i=0;b[i];i++)
		{
			num2=(num2*10+(int)b[i]-'0')%a;
		}
		cout<<gcd(a,num2)<<endl;
	    }
	}
}
