#include <bits/stdc++.h>
#define M 100005
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef pair<int , char> ii;

int main()
{
	int Cases;
	cin>>Cases;
	ii a[M];
	vector<int> v;
	int N , color , pos;
	char ch , lastcolor;
	ll ans , dif;
	
	while(Cases--)
	{
		scanf("%d %d" , &N , &color);
		for (int i = 0; i < color; ++i)
		{
			cin>>ch;
			scanf("%d",&pos);
			a[i] = ii(pos , ch);
		}

		sort(a , a + color);
		lastcolor = a[0].second;

		ans = 1LL;
		for (int i = 1; i < color; ++i)
		{
			if(a[i].second != lastcolor)
			{
				dif = a[i].first - a[i-1].first;
				ans = ((ll)ans * dif) % MOD;
			}	
			
			lastcolor = a[i].second;
		}
		printf("%lld\n", ans);
	}	
}
