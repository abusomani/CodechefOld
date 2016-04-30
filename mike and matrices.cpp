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
#define tr(c,i) for(typeof((c).begin());i!=(c).end();i++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x))!=(c).end()
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295


int P[100000],k,prime[1000000]={0};
void sieve()
{
	P[k++]=2;
	for(int i=3;i*i<1000000;i+=2)
		{
			if(!prime[i])
				{
					P[k++]=i;
					for(int j=i*i;j<1000000;j++)
						prime[j]=1;
				}
		}
	for(int i=1001;i<1000000;i+=2)
		{
			if(!prime[i])
				P[k++]=i;
		}
}
struct points
{
int	 x,y;
};
int main()
{ios_base::sync_with_stdio(false);
int n,m;
cin>>n>>m;
int a[n+1][m+1];
for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
int l;
cin>>l;
points p[l];
for(int i=0;i<l;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
ll e1=0,e2=0;
for(int i=0;i<l;i++)
	{
		if(p[i].x<=n&&p[i].x>=1&&p[i].y<=m&&p[i].y>=1)
			{
				if(e1!=-1)
				e1+=a[p[i].x][p[i].y];
			}
		else
			{
				e1=-1;
			}
		if(p[i].y<=n&&p[i].y>=1&&p[i].x<=m&&p[i].x>=1)
			{
				if(e2!=-1)
				e2+=a[p[i].y][p[i].x];
			}
		else
			{
				e2=-1;
			}
	}
	cout<<max(e1,e2);

	return 0;
}

