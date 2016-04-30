#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{long long n,k,temp,flag=0;
	cin>>n>>k;
	long long b[k];
	for(int i=0;i<k;i++)
	cin>>b[i];
	sort(b,b+k);
	long long x=0,sum=0;
	for(int i=0;i<k;i++)
		{temp=b[i];
		x=(temp*(temp-1)/2);
		if((x-sum+1)<=b[i])
			{if(b[i]%2)
				cout<<"Chef"<<endl;
			else
				cout<<"Mom"<<endl;
				
			flag=1;
			break;
			}
		sum+=b[i];
		}
	if(!flag)
		{x=n*(n+1)/2;
		sum=x-sum+1;
		if(sum%2)
		cout<<"Chef"<<endl;
		else
		cout<<"Mom"<<endl;
		}
	}
	return 0;
} 
