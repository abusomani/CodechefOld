#include<iostream>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int t=0,n=0;
cin>>t;
while(t--)
	{cin>>n;
	if(n%2==0)
	cout<<"ALICE"<<endl;
	else
	cout<<"BOB"<<endl;
	}
return 0;
}
