#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
		{
			int N,K;
			cin>>N>>K;
			int min=0;
			for(int i=1;i<=K;i++)
				{
					if(N%i>min)
						min=N%i;
				}
			cout<<min<<endl;
		}
	return 0;
}
