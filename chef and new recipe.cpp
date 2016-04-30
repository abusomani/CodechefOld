#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int test;	
cin>>test;
while(test--)
{
	int N;
	cin>>N;
	long long sum=0;
	int a[N],f=0;
	if(N==1)
		{
			int a1;
			cin>>a1;
			if(a1>2)
			cout<<"2\n";
			else
			cout<<"-1\n";
		}
	else if(N!=1)
	{
		for(int i=0;i<N;i++)
		{
		cin>>a[i];
		if(a[i]<2)
			f=1;
			else
				sum+=a[i];
		} 
	if(f)
	cout<<"-1\n";
	else
	
		{
			sort(a,a+N);
			sum+=2-a[0];
			cout<<sum<<endl;
			
		}
	}
}
return 0;
}
