#include<bits/stdc++.h>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int n,count=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	long long sum=0;
	for(int i=n-1;i>=0;i--)
		{if(count==2)
			{count=0;
			i--;
			}
			else
				{count++;
				sum+=a[i];
				}
		}
	cout<<sum<<endl;
	}
	return 0;
}
