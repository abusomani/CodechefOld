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
		int x,min1,min2;
		cin>>x;
		min1=x;
		cin>>x;
		min2=x;
		for(int i=2;i<n;i++)
			{
				cin>>x;
				if(x<min1)
					{
						if(min1<min2)
							min2=min1;
						min1=x;
					}
				else if(x>min1&&x<min2)
					min2=x;
				
			
			}	
		cout<<min1+min2<<endl;
	}

	return 0;
}

