#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int x,max=0,val;
	cin>>x;
	int a[x];
	for(int i=0;i<x;i++)
		cin>>a[i];
	sort(a,a+x);
	int count =1;
	 for(int i=0;i<x;i++)
		{if(a[i]==a[i+1])
		count++;
		else
			{if(count>max)
			{max=count;
			val=a[i];
			}
			count=1;
			}
		}
	cout<<val<<" "<<max<<endl;	
	}
return 0;
}
