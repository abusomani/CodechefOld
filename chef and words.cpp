#include<bits/stdc++.h>
using namespace std;
double a[27][27];
int main()
{//float a[26][26];
int n,k,t;
cin>>t;
while(t--)
	{cin>>n>>k;
	double ans=0;
	string s;
	cin>>s;
	int len1=s.size();
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			cin>>a[i][j];
		for(int i=0;i<n;i++)
		{
		
		string c;
		cin>>c;
		int len2=c.size();
		if(len1==len2)
			{
			int flag=0;
			double sum1=1,sum2=1,sum=1;
				while(c[flag]!='\0')
					{sum1*=a[s[flag]-'a'][c[flag]-'a'];
					sum2*=(1-sum1);
					flag++;
					}
			sum=pow(sum2,k-1)*sum1;
			ans+=sum;
			
			}
			
		}
			cout.setf(ios::fixed, ios::floatfield);
			cout<<setprecision(10)<<ans<<endl;
	}
return 0;
}
