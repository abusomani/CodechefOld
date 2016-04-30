#include<bits/stdc++.h>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin,(c).end()
#define tr(c,i) for(typeof((c).begin();i!=(c).end();i++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x))!=(c).end()
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295
 
int main()
{ios_base::sync_with_stdio(false);

int t;
cin>>t;
while(t--)
	{
		
		int n;
		cin>>n;
		int a[n+1][n+1],b[n+1][n+1];
		for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=i;j++)
					{
					cin>>a[i][j];
					b[i][j]=a[i][j];	
					}
			}
	/*	for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=i;j++)
					{
					cout<<a[i][j]<<" ";	
					}
				cout<<endl;
			}
	*/	
		for(int i=1;i<=n-1;i++)
			{
				for(int j=1;j<=i;j++)
					{
						int lower=b[i][j]+a[i+1][j];
						int rightlower=b[i][j]+a[i+1][j+1];
						
						if(lower>b[i+1][j])
							b[i+1][j]=lower;
						if(rightlower>b[i+1][j+1])
							b[i+1][j+1]=rightlower;
					}
			}
		/*
		for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=i;j++)
					{
					cout<<b[i][j]<<" ";	
					}
				cout<<endl;
			}
			
		*/	
		int max=-1;
		for(int i=1;i<=n;i++)
			{
				if(b[n][i]>max)
				max=b[n][i];
			}
		cout<<max<<endl;
	}
	return 0;
}

