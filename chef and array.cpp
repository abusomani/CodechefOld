#include<bits/stdc++.h>
using namespace std;
long long table[100007][100007];
long long createtable(long long n)
{
	for(long long i=1;i<n;i++)
		{
			for(long long j=0;j<n-i;j++)
				{
					table[i][j]=max(table[i-1][j],table[i-1][j+1]);
					//cout<<table[i][j]<<"  ";
				}
			//cout<<endl;
		}
}
int main()
{
	long long n;
	cin>>n;
	long long a[n];
	
	for(long long i=0;i<n;i++)
		{
		cin>>a[i];
		table[0][i]=a[i];
		//cout<<table[0][i]<<"  ";
		}
	//cout<<endl;
	createtable(n);
	long long m,x,y,minimum,maximum;
	long long sum=0;
	cin>>m>>x>>y;
		minimum=min(x,y);
		maximum=max(x,y);
		sum+=table[maximum-minimum][minimum];
	for(long long i=1;i<m;i++)
		{
			x=(x+7)%(n-1);
			y=(y+11)%n;
			minimum=min(x,y);
			maximum=max(x,y);
			//cout<<x<<"  "<<y<<endl;
			sum+=table[maximum-minimum][minimum];
			
		}
	cout<<sum;
	return 0;
}
