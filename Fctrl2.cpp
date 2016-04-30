#include <iostream>
#include <cstring>
#include <vector>
#include<fstream>
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
void print(vector<int> num)
{
	for(int i=(num.size()-1);i>=0;i--)
		cout<<num[i];
	cout<<endl;
}
int main()
{	int t;
	cin>>t;
	fstream fout("digits.txt",ios::out);
	while(t--)
	{
	int N;
	cin>>N;
	vector<int>number;
	number.push_back(1);
	for(int i=2;i<=N;i++) 
	multiply(i,number);
	//print(number);
		for(int i=(number.size()-1);i>=0;i--)
		fout<<number[i];
	}
	return 0;
}
