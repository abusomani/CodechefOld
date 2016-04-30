/*  Details -    codechef may'14  funagp	Seg tree based   */
#include <bits/stdc++.h>

#define M 			 100005
#define M1			 262144
using namespace std;
typedef long long  ll;

ll mulmod(ll A,ll B,ll mod)						// (a*b) %c
{
	long double ans;
	ll C;
	A = A%mod;   B = B%mod;
	ans = (long double)A*B;
	A = A*B;
	C = (ll)(ans/mod);
	A = A - C*mod;
	A = A%mod;
	if(A<0)		 A += mod;
	return A;
}

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


int N , R , S , D;
ll  p1 , p2 , st[M1] , a[M] , Sadd[M] , Dadd[M];

void create(int lo , int hi , int idx)
{
	if(lo == hi)
	{
		st[idx] = a[lo];
		return ;
	}
	int mid = (lo + hi)/2;
	create(lo , mid , 2*idx);
	create(mid + 1 , hi , 2*idx + 1);
	st[idx] = (st[2*idx] + st[2*idx + 1]) %p1;
}

void update_one(int lo , int hi , int u , int g , int idx)
{
	if(u < lo || u > hi)
		return ;
	//	helper term
	if(lo == hi)
	{
		st[idx] = pow(st[idx] , g , p2);
	}
	
	if(lo != hi)
	{	
		int mid = (lo + hi)/2;
		update_one(lo , mid , u , g , 2*idx);
		update_one(mid + 1 , hi , u , g , 2*idx + 1);
		st[idx] =  (st[2*idx] + st[2*idx + 1]) %p1;
	}
}

ll generate(int lo , int hi , int X , int Y)
{
	int x , y;
	x = max(X,lo);			y = min(Y,hi);
	x = x - X + 1;			y = y - X + 1;
	
	ll r1 = (Sadd[y] - Sadd[x-1]);			
	ll r2 = (Dadd[y] - Dadd[x-1]);			
	if(r1<0)	r1 += p1;
	if(r2<0)	r2 += p1;
	return (mulmod(S,r1,p1) + mulmod(D,r2,p1)) %p1;
}

void update_all(int lo , int hi , int u , int v , int idx)
{
	if(u > hi || v < lo)
		return ;
		
	st[idx] = (st[idx] + generate(lo , hi , u , v)) %p1;		
	int mid = (lo + hi)/2;
	if(lo != hi)
	{
		update_all(lo , mid , u , v , 2*idx);
		update_all(mid + 1 , hi , u , v , 2*idx + 1);
	}
}

ll query(int lo , int hi , int u , int v , int idx)
{
	int mid = (lo + hi)/2;
	if(u <= lo && v >= hi)
		return st[idx];
	else if(u > hi || v < lo)
		return 0;
	else
		return (query(lo , mid , u , v, 2*idx) + query(mid + 1 , hi , u , v, 2*idx + 1)) %p1;
}

int main()
{   
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
//	freopen("E://Test//in.txt" , "r" , stdin);
 	int Cases;
 	cin>>Cases;
 	int q , X , Y , g , type;
	ll r , kp , lastr;
 	while(Cases--)
    {
    	cin>>N>>q>>R>>p1>>p2;
    	kp = p1;
    	if(p1 != p2)
    		p1 = p1*p2;			//	here p1 is made p1*p2 because sometime we are taking mod by p1 and sometimes by p2 
    							//	so if we'll do like that ans will be wrong so we take mod by p1*p2 then at time of cout
    							//	we'll	take mod by required number.
    	
		lastr   = 1; 	
    	Sadd[0] = Dadd[0] = 0;
    	Sadd[1] = 1;
    	Dadd[1] = 0;
    	for(int i = 2 ; i<=N ; i++)
    	{
    		r = mulmod(lastr , R , p1);
    		lastr = r;
			Sadd[i] = (Sadd[i-1] + r) % p1;
    		Dadd[i] = (Dadd[i-1] + mulmod((i-1) , r , p1)) % p1;  
    	}
    	
    	for (int i = 1; i<=N; ++i)
    	{
    		cin>>a[i];
    	}
    	create(1 , N , 1);
    	
    	while(q--)
    	{
    		cin>>type;
    		switch(type)
    		{
    			case 0:
    				cin>>S>>D>>X>>Y;
    				update_all(1 , N , X , Y , 1);
    				break;

    			case 1:
    				cin>>X>>g;
    				update_one(1 , N , X , g , 1);
    				break;

    			case 2:
    				cin>>X>>Y;
    				cout<<(query(1 , N , X , Y , 1) % kp)<<endl;
    				break;
    		}
    	}
    }	
}
