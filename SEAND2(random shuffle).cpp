//	each time random_shuffle the string and try to get the most optimum one;

#include<bits/stdc++.h>
#include<algorithm>
#define M 100005
using namespace std;
int min(int a,int b)
{
	return (a<b)?a:b;
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	string b,str;
	int T = 15;
	int n,L,num2,c[M],sum,maxi;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>b>>n;
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
		}
		num2 = sum = maxi = 0;
		str = b;
		L = min(str.length(),T);
		for(int times = 0;times<L;times++)
		{
			sum = 0;
			//cout<<b<<endl;
			for(int j=0;j<n;j++)
			{
				for(int i=0;i<b.length();i++)
				{
					num2=(num2*10+(int)b[i]-'0')%c[j];
				}
				sum += num2;
				//cout<<j<<"      "<<num2<<endl;
				num2 = 0;
			}
			if(maxi < sum)
				str = b,
				maxi = sum;
				
			random_shuffle (b.begin(), b.end());
		}
		cout<<str<<endl;
	}
}	
