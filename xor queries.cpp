#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>v;
int main()
{ios_base::sync_with_stdio(false);
int m;
cin>>m;
while(m--)
	{int z,x,l,r,k,sum=-1,pos=1,count=0;;
	cin>>z;
	
	if(z==0)
		{ cin>>x;
		 v.push_back(x);
				 
		}
		else if(z==1)
		{
		 cin>>l>>r>>x;
				for(int j=l-1;j<r;j++)
					{if((v[j]^x)>sum)
						{
						sum=(v[j]^x);
						pos=j;
						}
					}
				cout<<v[pos]<<endl;
		}
		else if(z==2)
		{cin>>k;
				for(int i=1;i<=k;i++)
				v.pop_back();
		} 
			
		else if(z==3)
		{cin>>l>>r>>x;
				
				for(int j=l-1;j<r;j++)
					{if(v[j]<=x)
						count++;
					}
				cout<<count<<endl;
		}
				
		else if(z==4)
		{
		cin>>l>>r>>k;
				vector<int> tmp;
				for(int j=l-1;j<r;j++)
					tmp.push_back(v[j]);
				sort(tmp.begin(),tmp.end());
				cout<<tmp[k-1]<<endl;
		}
		
	}
	return 0;
}
