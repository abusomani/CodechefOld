#include<iostream>
using namespace std;
int main()
{
	int i,t;
	long int c1,c2;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>c1>>c2;
		if(c1>c2)
		{
			cout<<c1<<" "<<(c1+c2);
		}
		else
		{
			cout<<c2<<" "<<(c1+c2);
		}
	}
}

