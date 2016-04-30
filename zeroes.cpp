#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int a[10005];
	a[0]=0;
	for(int i=1;i<100;i++)
		{
			if(i%5==0)
				{
					a[i]=a[i-1]+i;
				}
			else
				a[i]=a[i-1];
			//cout<<a[i]<<endl;
		}
	while(t--)
	{
		int N;
		cin>>N;
		cout<<a[N]<<endl;
	}
	
	return 0;
}

