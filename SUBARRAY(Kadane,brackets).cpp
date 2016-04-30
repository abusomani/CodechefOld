#include <bits/stdc++.h>
#define M 100005
#define MOD 1000000007
#define inp(x)	  scanf("%d" , &x)
#define outp(x)	  printf("%lld\n" , x)
using namespace std;
typedef long long ll;
typedef pair<char,int> ii;

int N , a[M] , ans[M];
bool mark[M];
char str[M];
bool isOpen[260];
char rev[260];

ll maxSum(vector<int>& v)
{
	if(v.size() == 0)		return 0LL;
	if(v.size() == 1)		return v[0];
	ll max_so_far , curr_max;
	max_so_far = curr_max = v[0];
	
	for(int i = 1 ; i < v.size() ; ++i)
	{
		curr_max = max((ll)v[i], curr_max + (ll)v[i]);
		max_so_far = max(max_so_far , curr_max);
	}
	return max_so_far;
}

ll maxContinuousSum()
{
	int i , j;
	ll Ans = 0;
	vector<int> v;
	for(i=0; i<N ; ++i)
	{
		if(mark[i])
			v.push_back(ans[i]);
		else
		{
			Ans = max(Ans , maxSum(v));
			v.clear();
		}	
	}
	if(v.size())
		Ans = max(Ans , maxSum(v));
	return Ans;
}

ll solve()
{
	stack< pair<char,int> > st;
	for (int i = 0; i < N; ++i)
		mark[i] = ans[i] = 0;
	
	for (int i = 0; i < N; ++i)
	{
		if(isOpen[str[i]])
			st.push(ii(str[i] , i));
		else 
		{
			if(!st.empty() && rev[st.top().first] == str[i])
			{
				mark[i] = mark[st.top().second] = true;
				ans[st.top().second] = a[st.top().second] + a[i];
				st.pop();
			}
			else
			{
				st.push(ii(str[i] , i));
				mark[i] = false;
			}
		}
	}
	return maxContinuousSum();
}

int main()
{
//	freopen("E://t.txt" , "r" , stdin);
	int Cases;
	inp(Cases);

	rev[(int)'('] = ')';
	rev[(int)'{'] = '}';
	rev[(int)'['] = ']';
	rev[(int)'<'] = '>';

	memset(isOpen , false , sizeof isOpen);

	isOpen[(int)'('] = true;
	isOpen[(int)'{'] = true;
	isOpen[(int)'['] = true;
	isOpen[(int)'<'] = true;

	while(Cases--)
	{
		inp(N);
		scanf("%s" , str);
		for (int i = 0; i < N; ++i)
		{
			inp(a[i]);
		}
		outp(solve());
	}	
}
