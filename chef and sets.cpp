// @BEGIN OF SOURCE CODE

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


/*int P[100000],k,prime[1000000]={0};
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

int compare(const void *p1,const void *p2)
{
	int l=((struct T*)p1)->(data);
	int r=((struct T*)p2)->(data);
	 return (l-r);
}
*/

int main()
{ios_base::sync_with_stdio(false);

	int n,q;
	cin>>n>>q;
	vector <vector <int> > V;
	for(int i=0;i<=300005;i++)
		{
			vector <int> row;
			V.push_back(row);
			//cout<<V[i][0];
		}
	for(int i=0;i<=n;i++)
		V[i].push_back(i);
	
		int count=n,back=0;
	while(q--)
		{
			string s;
			int a,b;
			cin>>s;
			cin>>a>>b;
			if(s[0]=='U')
				{
					count++;	
					for(vector<int>::iterator i=V[a].begin();i!=V[a].end();i++)
						V[count].push_back(*i);
					for(vector<int>::iterator i=V[b].begin();i!=V[b].end();i++)
						V[count].push_back(*i);
						
					sort(V[count].begin(),V[count].end());
				}
			else
				{
					cout<<V[a][b-1]<<endl;
				}
		}
		
	
	return 0;
}


// @END OF SOURCE CODE
