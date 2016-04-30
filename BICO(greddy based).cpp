#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
#define LIM 100
using namespace std;
typedef long long ll;


#define debugger cerr
#define FOR(a,b)                for(int i = 0 ; i < n ; i++)    
#define FOREACH(v,c)            for(typeof((c).begin()) v = (c).begin() ; v != (c).end() ; ++v)
#define debug(args...)            {    mdbg,args; debugger<<endl;    }
#define PRINT_PAIR(p)            {    o<<"("<<p.first<<","<<p.second<<")";    }
#define PRINT_CONTAINER(o,v)    {    o<<"{"; FOREACH(it,v) o<<*it<<" "; return o<<"\b}";        }
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}}mdbg;
template<class T> ostream& operator<<(ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator<<(ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator<<(ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator<<(ostream& o,const pair<A,B> &p) { PRINT_PAIR(p); return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; FOR(0,n) debugger<<v[i]<<" "; debugger<<"\b}";}

ll Cr[M][M];
const ll g = 1e12;

ll sum(ll a , ll b)
{
	return (a+b) > g ? g+1 : (a+b);
}

void pre()
{
    for (int i = 0; i < LIM; ++i)
    {
        for (int j = 0; j <=i; ++j) 
        {
            if(i == 0 || j == 0)
                Cr[i][j] = 1;
            else
                Cr[i][j] = sum(Cr[i-1][j-1] , Cr[i-1][j]);
        }
    }

//    for (int i = 90; i < LIM; ++i)
//    {
//        for (int j = 90; j < LIM; ++j)
//        {
//            cout<<Cr[i][j]<<"  ";
//        }
//        cout<<endl;
//    }
}

int main()
{
	pre();
    int Cases;
    scanf("%d" , &Cases);

    int R , C;
    ll G , sum;
    while(Cases--)
    {
        scanf("%d %d %lld" , &R , &C , &G);
        if(C<=1)
        {
        	printf("1\n%lld\n" , G);
        	continue;
        }
        sum = 0;
        vector<ll> ans;

        for (int i = 1; ; ++i)
        {
            if(Cr[i][C] > G)
            {
                R = i;
                break;
            }
        }   
		R--;        
        G -= Cr[R][C];
        ans.push_back(Cr[R][C]);
        C--;
		
		debug(R , C , G);
		
        while(G != 0)
        {
            for (int i = R; ; --i)
            {
                if(Cr[i][C] <= G)
                {
                    R = i;
                    break;
                }
            }
            G -= Cr[R][C];
            ans.push_back(Cr[R][C]);
            C--;
        }

        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }    
}
