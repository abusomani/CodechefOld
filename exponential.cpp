#include<bits/stdc++.h>
using namespace std;
#define e 2.71828
int digits(double n)
{int temp=n;
	int count=0;
	while(temp)
		{
			count++;
			temp/=10;
		}
	return count;
}
int main()
{int t;
cin>>t;
while(t--)
{
double x=2.71828;
for(int i=2;i<=100;i++)
	{
		x*=x;
		cout<<digits(x)<<endl;
	}	
}

	
	return 0;
}
