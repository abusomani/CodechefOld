/*	RRFRIEND   number of pairs of vertices u, v which are connected to each other not directly by an edge 
	but by another vertex w such that w is a neighbour of both u and v.
	here for friend list we'll use bitset so i,j will be included in answer if f[i][j]=0 and i and j has atleast 
	one friend in common ( this operation is generally O(n) - chk whole frnd list )  for this we will and (&)
	their frnd list ( here in line: )  then check ANY bit is et or not if yes then we'll include in answer. 
*/
#include<bits/stdc++.h>
using namespace std;
#define M 20
bitset<M> frnd[M];
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int n;
	int ans = 0;
	string str[M];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		for(int j=0;j<n;j++)
		{
			if(str[i][j] == '1')
			{
				frnd[i].set(j);				//	creating frnd lst
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(str[i][j] == '0')
			if(i!=j	&& (frnd[i] & frnd[j]).any())
				//cout<<i<<" "<<j<<endl,
				ans++;
		}
	}
	cout<<ans<<endl;
}
