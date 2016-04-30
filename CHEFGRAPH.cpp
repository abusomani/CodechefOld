//		chfegraph not yet completed					till 	O(k*k)
/*
	9 3 7
	1 2 2 1
	2 0 4 1
	3 2 4 2
	5 1 8 2
	6 1 7 0
	6 1 8 0
	0 0 10 0		ans - 29047
*/

#include<bits/stdc++.h>
#define M 1000000007
#define MAX 10000
using namespace std;
struct vct
{
	int s,e;
	long long l1,l2;
	vct(int ss,int ee,long long l11,long long l22): s(ss),e(ee),l1(l11),l2(l22)
	{}
};
vector<vct> v;
bool cmp(vct a,vct b)
{
	if(a.l2 == b.l2)
		return a.l1<b.l1;
	return a.l2<b.l2;
}
long long mod_power(long long a, long long e, long long mod)
{
	if(e<0)		return 0;
    long long result = 1;
    a = a%mod;
    while (e > 0)
    {
        if (e%2 == 1)
           result = (result * a)% mod;
        e = e >> 1;
        a = (a * a) % mod;
    }
    return result;
}
int main()
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	long long answer[MAX];
	long long n , l1 , l2 , l , in , out;
	int m,k,p1,p2;
	long long sum = 0;	
	memset(&answer,-1,sizeof(answer));
	cin>>n>>m>>k;
	sum = mod_power(m,n,M);
	for(int i=0;i<k;i++)
	{
		cin>>l1>>p1>>l2>>p2;
		v.push_back( vct(p1,p2,l1,l2) );
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<k;i++)
	{
		if(v[i].l1 == 0 and v[i].l2 == n+1)		sum ++;
		else
		{
			in = 0;
			for(int j=0;j<k;j++)
			{
				if(v[j].l2 <= v[i].l1)
				{
					if(v[j].l2 == v[i].l1 && v[j].e != v[i].s)		continue;
					 l = mod_power(m,v[i].l1-v[j].l2-1,M);
					 if(l==0)
					 	l = 1;
					{
						if(answer[j] != -1)	
							in = (in + answer[j] * l) % M;
						else
							in = (in + (mod_power(m,v[j].l1-1,M) * l)) % M;
					}
				}
			}
			
			in = (in + mod_power(m,v[i].l1-1,M)) %M ;
			answer[i] = in;
			if(!answer[i])
				answer[i] = 1;
			out = mod_power(m,n-v[i].l2,M) % M;
			if(!in)		in = 1;
			if(!out)	out = 1;
			sum = ( sum + (in*out)%M ) %M;
		}
	}
	cout<<(sum%M)<<endl;
	v.clear();
}
