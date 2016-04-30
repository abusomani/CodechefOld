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
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int a[3]={0};//0-N,1-Y,2-I
		for(int i=0;i<n;i++)
			{
				if(s[i]=='N')
					a[0]++;
				else if(s[i]=='Y')
					a[1]++;
				else
				 a[2]++;
			}
		
		if(a[1]==0)
			{
				if(a[2]!=0)
					cout<<"INDIAN\n";
				else
					cout<<"NOT SURE\n";
			}
		else
			{
				if(a[2]==0)
					cout<<"NOT INDIAN\n";
				else
					cout<<"NOT SURE\n";
			}
		
	}

	return 0;
}

