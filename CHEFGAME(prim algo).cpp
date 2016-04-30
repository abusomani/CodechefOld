/*  Details -   Codechef April'13      based on Prim's algo   */
/*
	As the graph given in question is complete so Krushkal will time out because It takes ElogE time as E = V*V here so 
	log factor will be more than prims  ,  another thing here is as we got an edge of 0 len we need to break
*/

#include <bits/stdc++.h>

#define M 			 66666+5
#define MOD          747474747
#define INF 	     0x3f3f3f3f
#define s(x)         scanf("%d",&x)
#define p(x)         printf("%d",x)
#define sl(x)        scanf("%lld",&x)
#define pl(x)        printf("%lld",x)
#define nl           printf("\n");
#define pb			 push_back
#define mp			 make_pair
#define mset(x,val)  memset(&x,val,sizeof(x))
#define Fr           freopen("E://Test//in.txt","r",stdin);
#define Fw           freopen("E://Test//out.txt","w",stdout);
#define Frw 		 Fr	Fw

using namespace std;
typedef long long     ll;
//typedef __uint128_t   int128; 
typedef vector<int>   vi;
typedef vector<vi>	  vvi;
typedef pair<int,int> ii;
typedef vector<ii>    vii;
typedef vector<vii>   vvii;

int pt[M][5];
bool visit[M];
ll dist[M];
int N , D;

ll getDis(int a , int b)
{
	ll dis = 0;
	for (int i = 0; i < D; ++i)
	{
		dis += (ll)(pt[a][i] - pt[b][i])*(pt[a][i] - pt[b][i]);
	}
	return dis;
}

ll prim()
{
	ll maxDis , dis;
	int idx = -1 , cur;
	vector<ll> edges;
	memset(visit , false , sizeof(visit));
	visit[0] = true;
	cur = 0;
	
	//	here prim's algo is used - first from one point distance is given to every point then after we choose maximum 
	//	among them , visit it and update all other vertices according to this vertex and keep this maxDis as taken edge
	
	for(int i = 1; i < N; ++i)
		dist[i] = getDis(0 , i);
	
	while(true)
	{
		maxDis = 0;
		for (int i = 0; i < N; ++i)							//	choosing maximum
		{
			if(!visit[i])
			{
				if(dist[i] > maxDis)
				{
					maxDis = dist[i];
					idx = i;
				}
			}
		}
		if(maxDis == 0)	break;
		visit[idx] = true;
		
		for (int i = 0; i < N; ++i)							//	updating other vertices according to this point 
		{
			if(!visit[i])
				dist[i] = max(dist[i] , getDis(idx , i));
		}		
		edges.push_back(maxDis);
	}
	ll ans = 1;
	for (int i = 0; i < edges.size(); ++i)
	{
//		if(edges[i] != 0)
		ans = ((ll)ans * (edges[i] % MOD)) % MOD;
	}
	return ans;
}

int main()
{   
//  FILErw
 	int Cases;
 	scanf("%d" , &Cases);
    while(Cases--)
    {
    	scanf("%d %d" , &N , &D);
    	for (int i = 0; i < N; ++i)
    	{
    		for (int j = 0; j < D; ++j)
    		{
    			scanf("%d" , &pt[i][j]);
    		}
    	}
    	printf("%lld\n", prim());
    }
}
