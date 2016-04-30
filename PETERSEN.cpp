#include<bits/stdc++.h>
#define M 214748364
using namespace std;
struct use
{
	char c;
	int num;
	use()
	{}
	use(char ch,int num)
	{
		this->c = ch;		this->num = num;
	}
};
string str;
int bfs(int a[10][3],use u[10],int s)
{
	
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int a[10][3] = {{1,5,4},{0,6,2},{1,3,7},{2,4,8},{0,3,9},{0,8,7},{1,8,9},{2,5,9},{3,5,6},{4,6,7}};
	use u[10];
	int source;
	for(int i=0;i<5;i++)
	{
		u[i].c = 'A'+i;		u[i].num = i;
		u[i+5].c = 'A'+i;	u[i+5].num = i+5;
	}
	int t;
	cin>>t;
	while(t--)
	{
		cin>>str;
		int l = str.length();
		for(int i=1;i<l;i++)
		{
			if(str[i]==)
		}
		source = str[0]-'A';
		int a1 = bfs(a,u,source);
		source = str[0]-'A'+5;
		int a2 = bfs(a,u,source);
		if(a1==M && a2==M)	cout<<-1<<endl;
		else
			cout<<min(a1,a2)<<endl;
	}
}
