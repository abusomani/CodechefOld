#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long a;
	int n,k,i,p;
	cin>>a>>n>>k;
	for(i=0;i<k;i++)
	{
	cout<<a%(n+1)<<" ";
	a=(int)a/(n+1);
    }
}
