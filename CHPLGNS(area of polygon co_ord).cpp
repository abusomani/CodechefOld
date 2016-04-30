/*http://www.mathopenref.com/coordpolygonarea.html      <-  formula for getting area of polygon */
#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll , int> ii;

int main()
{
	int Cases;
	cin>>Cases;
	ll x[M] , y[M] , ans[M] , polygons , N;
	ll area;
	vector<ii> v;

	while(Cases--)
	{
		cin>>polygons;
		
		for(int p = 0 ; p<polygons ; p++)
		{
			cin>>N;
			for(int i = 0 ; i<N ; i++)
			{
				cin>>x[i]>>y[i];
			}
			x[N] = x[0];	y[N] = y[0];

			area = 0;
			for(int i = 1 ; i<=N ; i++)
			{
				area = area + (ll)y[i]*x[i-1] - (ll)x[i]*y[i-1];
			}
			if(area < 0)		
				area = -area;

			v.push_back(ii(area , p));
		}
		sort(v.begin() , v.end());
		for(int i = 0 ; i<polygons ; i++)
		{
//			cout<<i<<" ->  "<<v[i].first<<"  "<<v[i].second<<endl;
			ans[v[i].second] = i; 
		}

		for(int i = 0 ; i<polygons ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		
		v.clear();
	}	
}
