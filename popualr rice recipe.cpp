#include<bits/stdc++.h>
using namespace std;
struct voting
	{char name[25];
	int vote;
	};
int search(voting v[],char c[],int n )
	{for(int i=0;i<n;i++)
		{//if(!strcmp(v[i].name,c))
			cout<<strcmp(v[i].name,c)<<endl;
			return i;
		}
	return -1;
	}
int main()
{int t;
cin>>t;
while(t--)
	{
		int n,count=0,tempvote;char tempname[25];
		cin>>n;
		voting v[n];
		cin>>v[count].name>>v[count++].vote; 
		for(int i=1;i<n;i++)
			{cin>>tempname>>tempvote; 
			int x=search(v,tempname,count);
			if(x==-1)
				{
				strcpy(v[count].name,tempname);
				v[count++].vote=tempvote;
				}
			else
				{v[x].vote=tempvote;
				}
			}
		int sum=0;cout<<count<<endl;
		for(int i=0;i<count;i++)
			{cout<<v[i].name<<" "<<v[i].vote<<endl;
			sum+=v[i].vote;
			}
		cout<<sum<<endl;
	}
	return 0;
}
