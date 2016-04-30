// March '15  Partial		http://ideone.com/hdsLJC

#include <bits/stdc++.h>
#define M 100005
using namespace std;
typedef long long ll;

int oidx[M] , zidx[M];
int a , b;

int fzidx(int x)
{
	if(x>0)
		return zidx[x];
	else
		return a-1;
}

int foidx(int x)
{
	if(x>0)
		return oidx[x];
	else
		return a-1;
}
int main() 
{
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int t,n,k,q,o,x,z,r;
	int one[M] , zero[M];
	ll  ans[M];
	string str;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		cin>>str;
		o = z = 0;
		int l = str.length();
		one[0] = zero[0] = 0;
		for(int i=0;i<l;i++)
		{
			if(str[i] == '0')
			{	
				z++;
				zero[i] = z;
				zidx[z] = i;
				if(i>0)	  one[i] = one[i-1];
			}
			else
			{
				o++;
				one[i] = o;
				oidx[o] = i;
				if(i>0)	  zero[i] = zero[i-1];
			}
		}
		
		while(q--)
		{
			cin>>a>>b;
			a--;	b--;
			if(b-a+1 <= k)
			{
				r = b-a+1;
				cout<<(r*(r+1))/2<<endl;
				continue;
			}
			
			r = (k*(k+1))/2;
			ans[a+k-1] = r;
			/*
				for passing last test cases instead of looping use binary search
				Ans = ton(k);
				xtra = ton(b) - ton(a+k-1);
				pos  = upper_bound(save+a+k , save+b , a-1) - save - a - k;
	
				negxtra = (ll)(a-1)*(pos);
				if(pos+a+k <= b)
					negxtra += savetill[b] - savetill[pos+a+k-1];
					
				Ans += xtra - negxtra;
			*/
			
			for(int i=a+k;i<=b;i++)
			{
				x = max(fzidx(zero[i]-k) , foidx(one[i]-k));
				ans[i] = (ll) ans[i-1] + i - max(x,a-1);
			}
			cout<<ans[b]<<endl;
		}
	}
	
	return 0;
}
