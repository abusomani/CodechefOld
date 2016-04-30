#include<bits/stdc++.h>
#include<vector>
using namespace std;
void multiply(int n,vector<int>&number) // multiplies  'number' by n
{
	int carry=0;
	for(int i=0;i<number.size();i++)
	{
		int num = n * number[i];
		number[i] = (char)((num+carry)%10);
		carry = (num+carry)/10;
	}
	while(carry)
	{
		number.push_back(carry%10);
		carry/=10;
	}
}

int main()
{int t;
cin>>t;
while(t--)
	{
		int a,b;
		long long sum=0;
		cin>>a>>b;
		if(a==1||b==0)
		cout<<"1\n";
		else
			{
				vector<int>number;
				number.push_back(a);
				for(int i=2;i<=b;i++) 
				multiply(a,number);
				for(int i=0;i<number.size();i++)
				sum+=number[i];
				cout<<sum<<endl;
			}
	}
	return 0;
}
