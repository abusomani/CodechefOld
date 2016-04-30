#include <bits/stdc++.h>
#define M 100003
using namespace std;
typedef long long ll;

struct frog
{
	int val;
	int pos;
	frog(int v , int pos) : val(v) , pos(pos)
	{
	}
};

bool cmp(frog a , frog b)
{
	return (a.val < b.val);
}

class Disjset
{
	private:
		vector<int> s;
	public:
	Disjset(int num)
	{
		for(int i=0;i<num;i++)
	    s.push_back(-1);
	}
	int find(int x)					// 	non-recursive
	{								
		if(s[x]<0)					// 	for recursive in else - return s[x] = find(s[x])
			return x;
		int y = x;
		for( ; s[y]>0; y=s[y]);
		int z = y;
		for( ; x!=z ; x=y)
		{
			y = s[x];
			s[x] = z;
		}
		return z;		
	}
	void dounion( int root1,int root2)
	{
		root1 = find(root1);
		root2 = find(root2);
		if(root1 == root2)
			return ;
		if(s[root1]>=s[root2])
		{
			s[root2]+=s[root1];
			s[root1]=root2;
		}
		else
		{
			s[root1]+=s[root2];
			s[root2]=root1;
		}
	}
	void show()
	{
		int num=s.size();
		for(int i=0;i<num;i++)
	    cout<<i<<"-> "<<s[i]<<endl;
	}
};

int main()
{
	Disjset ds(M);
	int N , K , P;
	int a , b;
	cin>>N>>K>>P;
	vector<frog> v;
	for(int i = 0 ; i<N ; i++)
	{
		cin>>a;
		v.push_back(frog(a,i+1));
	}
	sort(v.begin() , v.end() , cmp);
	
	for(int i = 1 ; i<N ; i++)
	{
		if(v[i].val - v[i-1].val <= K)
		{
			ds.dounion(v[i].pos , v[i-1].pos);
		}
	}
		
	while(P--)
	{
		cin>>a>>b;
		if(ds.find(a) == ds.find(b))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
}
