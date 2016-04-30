#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
		while(t--)
			{
				string n;
				cin>>n;
				int a[10]={0},count=0;
				for(int i=0;i<n.size();i++)
					a[n[i]-48]++;
				for(int i=0;i<10;i++)
					{
						if(i==4||i==7)
							continue;
						else
							count+=a[i];
					}
				cout<<count<<endl;
			}
}
