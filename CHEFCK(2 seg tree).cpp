//	chefck

#include <bits/stdc++.h>
#define M 100000
#define MOD 1000000007
#define M_P 10000
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll N,K,Q;
ll A[M];
int pos[M_P];
ll L1, La, Lc, Lm, D1, Da, Dc, Dm ;
vector<ii> q;
int alpha , beta;

int start[M_P]; 
int common[M_P];

ll pow(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    base = base%modulus;
    while (exponent > 0)
    {
        if (exponent%2 == 1)
           result = (result * base)% modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

void store(int x)
{
	for(int j=1 ; j<pos[A[x]] ; j++) 
		start[alpha++] = (A[j]);			
	for(int j=pos[A[x]] ; j<x ; j++) 
		common[beta++] = (A[j]);	
}

void generate(ll a,ll  b,ll c,ll d,ll e,ll f,ll r,ll s,ll t,ll m,ll A1)
{
	A[1] = A1;
	for(int x = 2 ; x<=N ; x++)
	{
		if(pow(t,x,s) <= r)        
		{
			A[x] = (a*A[x-1]*A[x-1] + b*A[x-1] + c) % m ;
		}
		else
		{
			A[x] = (d*A[x-1]*A[x-1] + e*A[x-1] + f) % m ;
		}
	
//		if(pos[A[x]] == -1)
//			pos[A[x]] = x;
//		else
//		{
//			store(x);
//			return;
//		}

	}
}

void Query()
{
	ll L , R;
	for(int i = 1 ; i<=Q ; i++)
	{
		L1 = (La * L1 + Lc) % Lm;
		D1 = (Da * D1 + Dc) % Dm; 
		L = L1 + 1;
		R = min(L + K - 1 + D1, N);
		q.push_back(ii(L,R));
	}
}

int seg1[M_P];
int seg2[M_P]; 
 
void make_tree(int* seg,int *a,int lo,int hi,int idx)
{
	if(hi == lo)
	{
		seg[idx] = a[lo];
		return;
	}
	
	int mid = (lo + hi)/2;
	make_tree(seg,a,lo,mid,2*idx);
	make_tree(seg,a,mid+1,hi,2*idx+1);
	
	seg[idx] = min(seg[2*idx+1] , seg[2*idx]);
}

int query(int* seg,int lo,int hi,int idx,int i,int j)
{
	if(i<=lo && j>=hi)
        return seg[idx];
    else if(i>hi || j<lo)
        return (INT_MAX);
    else
    {
    	int mid = (lo+hi)/2;
    	int x = query(seg,lo,mid,2*idx,i,j);
    	int b = query(seg,mid+1,hi,2*idx+1,i,j);
    	return min(x,b);
    }
}

int main()
{
	int a, b, c, d, e, f, r, s, t, m, A1;
	int u,v,dis,mina,minb;
	int u1,v1,u2,v2;
	ll as,ap,ans,ans1,ans2;
	as = 0;
	ap = 1;
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	memset(&pos , -1 , sizeof(pos));
	vector<int> mid;
	{
		cin>>N>>K>>Q;
		cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>A1;
		cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
		
		generate(a, b, c, d, e, f, r, s, t, m, A1);
		
		
//		for(int i = 1; i<=N; i++)
//			cout<<A[i]<<"  ";
		
		bool f = true;
		for(int i = 1; i<=N; i++)
		{
			if(pos[A[i]] == -1)
				pos[A[i]] = i;
			else
			{
				f = 0;
				store(i);
				break;
			}	
		}
		
		if(f)
		{
			for(int i = 0 ; i<N ; i++)
				start[alpha++] = A[i+1];
		}
	/*	cout<<"$"<<alpha<<"&"<<beta<<endl;
		
		for(int i = 0; i<alpha; i++)
			cout<<start[i]<<" ";
		cout<<endl;
		for(int i = 0; i<beta; i++)
			cout<<common[i]<<" ";
		cout<<endl;
	*/
		if(alpha)	make_tree(seg1 , start , 0 , alpha-1 , 1);
		if(beta)	make_tree(seg2 , common , 0 , beta-1 , 1);

		minb = seg2[1];
		
//		cout<<alpha<<" "<<beta<<endl;
		
		Query();
		/*
		q.push_back(ii(1,1));
		q.push_back(ii(1,4));
		q.push_back(ii(2,5));
		q.push_back(ii(7,8));
		q.push_back(ii(6,12));
		q.push_back(ii(1,14));
		q.push_back(ii(12,14));
		*/
		
		for(int i = 0 ; i<q.size() ; i++)
		{
			u = q[i].first ; 		v = q[i].second	;	
			dis = v - u + 1;
			if(v<=alpha)
			{
//				cout<<" 1% "<<u-1<<"  "<<v-1<<endl;
				ans = query(seg1,0,alpha-1,1,u-1,v-1);
			}
			else
			{
				if(v>alpha && u<=alpha)
				{	
//					cout<<" 2$ "<<u-1<<"  "<<v-1<<endl;
					ans1 = query(seg1,0,alpha-1,1,u-1,alpha-1);
					
					v = v-alpha;
					if(v>beta)
						ans2 = minb;
					else
						ans2 = query(seg2,0,beta-1,1,0,v-1);
				
					ans = min(ans1 , ans2);
				}
				else
				{
//					cout<<" 3@ "<<u-1<<"  "<<v-1<<endl;
					
					u = u-alpha;	v = v-alpha;
					u = u%beta;	v = v%beta;
					if(dis>=beta)
					{
						ans = minb;
					}
					else
					{	
						if(v>=u)
						{
//							cout<<" 3.5!  "<<u-1<<"  "<<v-1<<endl;
							ans = query(seg2,0,beta-1,1,u-1,v-1);
						}
						else
						{
//							cout<<" 3.55~  "<<u-1<<"  "<<v-1<<endl;
					
							ans2 = query(seg2,0,beta-1,1,u-1,beta-1);
							ans1 = query(seg2,0,beta-1,1,0,v-1);
							ans = min(ans1 , ans2);
						}
					}
				}
			}
	//		cout<<i<<" : "<<ans<<endl;
			as += ans;
			ap = (ap*ans) % MOD;
		}
		cout<<as<<" "<<ap<<endl;
		q.clear();
	}
}
