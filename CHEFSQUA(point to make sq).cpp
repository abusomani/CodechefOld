#include <bits/stdc++.h>
#define M 2005
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int x1 , y11 , x2 , y2 , x3 , y3 , x4 , y4;
bool f;

void getsqpoint(ii a , ii b)
{
	x3 = b.first - b.second + a.second;			//	3 vertice of square
	y3 = b.second + b.first - a.first;
    x4 = a.first - b.second + a.second;			//	4 vertice of square
    y4 = a.second + b.first - a.first;
}
int main()
{
	int N , x , y , require;
	vector<ii> v;
	set<ii> st;
	bool f1 , f2;
	
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d" , &x , &y);
		v.push_back(ii(x , y));
		st.insert(ii(x , y));
	}
	
	if(st.size() <= 2)		{		require = 4 - st.size();		goto out;		}

	require = 2;
	for (set<ii>::iterator i = st.begin(); i != st.end(); ++i)
	{
		for (set<ii>::iterator j = i; j != st.end(); ++j)
		{
			ii a = *i;		ii b = *j;
			if(a == b)		continue;
			getsqpoint(a,b);
			f1 = st.count(ii(x3 , y3));
			f2 = st.count(ii(x4 , y4));
			
			if(f1 || f2)
			{
				if(f1 && f2)
				{
					require = 0;
					goto out;
				}
				require = 1;
			}
		}
	}

	out:
		printf("%d\n", require);
}
