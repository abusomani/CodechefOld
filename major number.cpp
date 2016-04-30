#include<bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{
		int n,x;
		cin>>n;
		vector<int> vec;
		for(int i=0;i<n;i++)
			{cin>>x;
			vec.push_back(x);
			}
			sort(vec.begin(),vec.end());
		int count=1,max=-1,val=vec[0];
		for(int i=0;i<n-1;i++)
			{
				if(vec[i]==vec[i+1])
					count++;
				else
					{if(count>max)
						{
						max=count;
						val=vec[i];
						}
						count=1;
						
					}
			}
		if(max>n/2)
		cout<<val<<endl;
		else
		cout<<"NO MAJOR\n"<<endl;
		
		
	}
	return 0;
}
