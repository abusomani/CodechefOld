#include <bits/stdc++.h>
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

ll get(int n)
{
	return (ll)n*(n+1)/2;
}

int main()
{
    int Cases;
    scanf("%d" , &Cases);

    int N , M , k;
	ll m , min_lim , max_lim , ans , alpha , beta;
    while(Cases--)
    {
        scanf("%d %d" , &N , &M);
        min_lim = max_lim = 0;
        k = (2*N)/M;
        ans = k;
        
		alpha = ceil((double)(N+1)/M);
        min_lim += (alpha-1);
        min_lim -= (k-alpha+1)*N;
        min_lim += (get(k) - get(alpha-1))*M;
        
        max_lim = (get(k)*M - k)/2;
        if(M&1)
        	max_lim -= (k/4);
        else
        	max_lim -= (k/2);
//    	printf("!%lld\n" , max_lim);
		
//		printf("^%lld %d %lld %lld\n" , max_lim , k , max_lim - (k/2) , max_lim - (k/4));
	
//	    max_lim = 0;
//        for (int i = 1; i <= k; ++i)
//        {
//        	m = i*M;
//        	alpha = (m-1)/2;
//          	max_lim += alpha;
////        	debug("$" , max_lim);
//        }
//        printf(".%lld\n" , max_lim);
        
        ans += max_lim - min_lim;
        printf("%lld\n", ans);
    }    
}
