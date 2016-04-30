#include<bits/stdc++.h>
#include<set>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295
struct Point
{
	ll x,y;
};
/*ll compareX(const void *a,const void *b)
{
	Point *p1=(Point*)a,*p2=(Point*)b;
	
	return (p1->x-p2->x);
}

int compareY(const void *a,const void *b)
{
	Point *p1=(Point*)a,*p2=(Point*)b;
	
	return (p1->y-p2->y);
}*/
ll dist(Point p1,Point p2)
{
	return (abs(p1.x-p2.x)+abs(p1.y-p2.y));
}
ll max(ll a,ll b)
{
	return (a>b)?a:b;
}
/*int bruteforce(Point p[],int n)
{
	int max=-1;
	
}*/
int main()
{ios_base::sync_with_stdio(false);
	int n;
	//cout<<INT_MAX;
	cin>>n;
	Point p[n];
	for(int i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
		}
	ll q;
	cin>>q;
	while(q--)
		{
			char c;
			ll a,b,c1;
			cin>>c;
			if(c=='Q')
				{
					cin>>a>>b;
					ll distance=-1;
					for(int i=a;i<b;i++)
						{
							for(int j=i+1;j<=b;j++)
								{
								if(dist(p[i],p[j])>distance)
									distance=dist(p[i],p[j]);	
								}
						}
					cout<<distance<<endl;
				}
			else if(c=='U')
				{
					cin>>a>>b>>c1;
					p[a].x=b;
					p[a].y=c1;
				}
		}
	
	
	return 0;
}
