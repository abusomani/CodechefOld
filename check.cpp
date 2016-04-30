#include<iostream>
#include<cmath>
int mod=pow(10,9)+9;
using namespace std;
int main()
{int ways=10000000,sum=1;
for(int i=1;i<=ways;i++)
	sum=sum*2%mod;
	cout<<sum;
	return 0;
}
