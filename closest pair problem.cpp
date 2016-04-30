//		not working properly

#include<bits/stdc++.h>
#define sqr(x)  ((x)*(x))
#define M 1000
#define MAX 2147483647
using namespace std;
typedef pair<int,int> ii;
bool cmpY(ii x,ii y)
{
	return (x.second - y.second);
}
int dist(ii x,ii y)
{
	return sqr(x.second - y.second) + sqr(x.first-y.first);
}
int brute(ii v[],int n)
{
	int minv = MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			minv = min(minv,dist(v[i],v[j]));
		}
	}
	return minv;
}
int stripclosest(ii v[],int n,int d)
{
	int minv = MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n && (v[j].second - v[i].second) < d ; j++)
		{
			if(dist(v[i],v[j]) < d)
				minv = min(minv,dist(v[i],v[j]));
		}
	}
	return minv;
}
int closest(ii vx[],ii vy[],int n)
{
	if(n<=3)
	{
		return brute(vx,n);
	}
	int mid = n/2;
	ii midpoint = vx[mid];
	ii vyl[mid],vyr[n-mid+1];
	
	int l=0,k=0;
	for(int i=0;i<n;i++)
	{
		if(vx[i].first < midpoint.first)
		{
			vyl[k++] = vx[i];
		}
		else
		{
			vyr[l++] = vx[i];
		}
	}
	int d1 = closest(vx,vyl,mid);
	int d2 = closest(vx+mid,vyr,n-mid+1);
	int d = min(d1,d2);
	
	ii strip[n];
	k = 0;
	for(int i=0;i<n;i++)
	{
		if(abs(vx[i].first - midpoint.first) < d)
		{
			strip[k++] = vx[i];
		}
	}
	return min(d,stripclosest(strip,k,d));
}

int main()
{
	int n,a,b;
	cout<<"Enter number of points\n";
	cin>>n;
	ii vx[M],vy[M];
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		vx[i] = ii(a,b);
		vy[i] = ii(a,b);
	}
	sort(vx , vx + n);
	sort(vy , vy + n  , cmpY);
	cout<<"Min distance is "<<sqrt(closest(vx,vy,n))<<endl;		// closest returns square of min distance
}
