
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
#define tr(c,i) for(typeof((c).begin());i!=(c).end();i++)
#define present(c,x) ((c).find(x)!=(c).end())
#define cpresent(c,x) (find(all(c),x))!=(c).end()
#define ll long long
#define MOD 1000000007
#define mod 100005
#define unsigned32 4294967295



int P[10003],k,prime[10003];
void sieve()
{
	P[k++]=2;
	for(int i=3;i*i<1000003;i+=2) // i will go upto 1000
		{
			if(!prime[i])
				{
					P[k++]=i;
					for(int j=i*i;j<1000003;j++)
						prime[j]=1;
				}
		}
	for(int i=1001;i<1000003;i+=2) //hence we continue the loop from 1001
		{
			if(!prime[i])
				P[k++]=i;
		}
}


ll int subset[10010][10010];

bool SubsetSumCheck(int w[],int l,int r,int w1)
{
    for (int i=l;i<=r;i++)
      subset[0][i] = true;
    for (int i =1;i<=w1;i++)
      subset[i][0] = false;
     for (int i =1;i<=w1;i++)
     {
       for (int j =l;j<=r;j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i>=w[j-1])
           subset[i][j] = subset[i][j]||subset[i - w[j-1]][j-1];
       }
     }
     return subset[w1][r];
}



int main()
{ios_base::sync_with_stdio(false);


for(int i=0;i<1500;i++);
    ll n,q;
    cin>>n>>q;
    
    int i,j;
    int a,l,x,r,previousweight,previousweight1,w1;
  
    int w[n+1];
    for(i=0;i<n;i++)
    {
        cin>>w[i];
    }
    while(q--)
    {
        
        cin>>a;
       
        if(a==1)
        {
            cin>>l>>x;
            l--;
            w[l]=x;
        }
        else if(a==2)
        {
            cin>>l>>r;
            l--;r--;
            for( i=l,j=r;i<=j;i++,j--)
            {
                swap(w[i],w[j]);
            }
           
        }
        else
        {
        	
            cin>>l>>r>>w1;
            l--;
            bool flag=SubsetSumCheck(w,l,r,w1);
            
            if(flag==false)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
             
            subset[w1][r]=0;
        }
    }
    return 0;
}  
