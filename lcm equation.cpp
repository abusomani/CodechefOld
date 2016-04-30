// @BEGIN OF SOURCE CODE

#include<bits/stdc++.h>
#include<set>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin,(c).end()
#define tr(c,i) for(typeof((c).begin());i!=(c).end();++i)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x))!=(c).end()
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295

using namespace std;

int check[500001];

vector<long long int> v;

void seive()
{
    int i,j;
    check[0] = 0;
    check[1] = 0;
    
    for(i=2; i<=500001; ++i)
        check[i] = 1;

    for(i=2; i<=sqrt(500001); ++i)
	{
        if(check[i])
		{
        	
            for(j=2; j<= 500001/i; ++j)
                check[i*j] = 0;
            
        }
    }

    for(i=2; i<=500001; ++i)
	 if(check[i]) 
            v.push_back(i);
    
}

ll int subset[10010][10010];

bool SubsetSumCheck(int w[],int l,int r,int w1)
{
    for (int i=l;i<=r;++i)
      subset[0][i] = true;
    for (int i =1;i<=w1;++i)
      subset[i][0] = false;
     for (int i =1;i<=w1;++i)
     {
       for (int j =l;j<=r;++j)
       {
         subset[i][j] = subset[i][j-1];
         if (i>=w[j-1])
           subset[i][j] = subset[i][j]||subset[i - w[j-1]][j-1];
       }
     }
     return subset[w1][r];
}


long long calculate(int n, int k)
{
    if(k==1) 
		return n;
    if(k> n/2+1)
	 k = n/2+1;
    
	vector<ll> lcm;
	int i,j;
	
	for(j=0; j<k; ++j)
        lcm.push_back(n-j);
	
	ll x = 1;
	
	
	for(int op=0;op<1500;op++);
	
	for(i=0;i<v.size();)
	{
        if(v[i]> k) break;

        int count = 0, count1= 0;
      
	    for(j=0; j<lcm.size(); ++j)
		{
            if(lcm[j]%v[i]==0)
			{
                
                lcm[j] = lcm[j]/v[i];
                
				if(lcm[j]%v[i]==0) 
				count1++;
                
				count++;
            }
          

        }
        if(count>=1) 
		x = (x*v[i])%MOD;
        
        if(count1 <= 1) ++i;
	}
	

	for(i=0; i<lcm.size(); ++i)
        x= (x*lcm[i])%MOD;
	
	return x;
}

int main(int argc,char** argv)
{
 	seive();
    
    int t;
    cin>>t;
    
	int i,j;
    ll n,k,a,b,c,m;
    cin>>n>>k;
    
    cin>>a>>b>>m;
    
    vector<ll> C,D;
    
    for(i=0; i<t-1; ++i)
	{
		cin>>c;
		C.push_back(c);
	}
	
	for(i=0; i<t-1; ++i)
	{
		cin>>c;
		D.push_back(c);
	}
	
    int arr[1003][503];

    for(i=0; i<1001; ++i)
	{
        for(j=0; j<501; ++j)
		{
            arr[i][j] = -1;
        }
	}
	
	
	ll x = calculate(n, k);
	
	if(n<=1000)
	 arr[n][k] = x;
	cout<<x<<endl;
	
	for(i=0; i<t-1; ++i)
	{
		n = 1+(a*x + C[i])%m;
		k = 1+(b*x + D[i])%n;
		
		if(n<=1000)
		{
        	    if(arr[n][k]!=-1)
				{
        	        cout<<x<<endl;
        	    }
				else
				{
            	    x = calculate(n,k);
            	    cout<<x<<endl;
                	arr[n][k] = x;
            	}
		}
		
		else
		{
            x = calculate(n, k);
            cout<<x<<endl;
		}
	}



    return 0;
}

