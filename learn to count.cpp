#include<bits/stdc++.h>
using namespace std;
int toBinary(int n)
{
 int count=0;
 while(n>0)
 	{
 		if(n%2==0)
 		count++;
 		else
 		return count;
 		n/=2;
	}   //10100

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
			int n;
			cin>>n;
			cout<<toBinary(n)<<endl;
			
	}
	
	return 0;
}
