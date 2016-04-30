#include<iostream>
#include<math.h>
using namespace std;
int req;
int max(int a,int b)
{
	if(a>=b)  return a;
	else return b;
}
void show(int *a,int n)
{
	for(int i=1;i<pow(2.0,n);i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				sum+=a[j];
			}
	    }
	    cout<<endl;
	    if(req==sum) { cout<<"Yes\n";  return; }
	}
    cout<<"No\n";
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>req;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		show(a,n);
	}
}
