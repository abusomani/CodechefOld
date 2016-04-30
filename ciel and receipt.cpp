#include<iostream>
using namespace std;
int a[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int x,count=0;
	cin>>x;
	for(int i=11;i>=0;i--)
		{count+=x/a[i];
		x=x%a[i];
		}
	cout<<count<<endl;
	}
return 0;
}
