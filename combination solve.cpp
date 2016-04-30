#include<iostream>
#define M  10000007
using namespace std;
int main()
{
	int t,i,j,n=100;
	int save[101][101]={0};
	for(i=1;i<=n;i++)
	{  save[i][1]=i;   save[i][i]=1; }
	for(i=2;i<=n;i++)
	{
	//	cout<<save[i][1]<<"   ";
		for(j=2;j<i;j++)
		{
			save[i][j]=(save[i-1][j]+save[i-1][j-1])%M;
	//		cout<<save[i][j]<<"   ";
		}
	//	cout<<endl;
	}
	long long num,k,res;
		cin>>num>>k;
		if(num==k)  cout<<"1\n";
		else if(k>num)     cout<<"-1\n";
		else if(k==1  && num!=0)   cout<<"1\n";
		else
		{
			res=save[num-1][k-1];
		    cout<<res<<endl;
		}
}

