#include <bits/stdc++.h>
#define MAX 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

int rate[MAX], delrate[MAX];
vector<pair<int,int> > negrate;

int main()
{
    int Cases;
    scanf("%d" , &Cases);

    int N, K, M, a, b, p;
    ll sum ;
    while(Cases--)
    {
        sum = 0;
        negrate.clear();
        memset(delrate, INF, sizeof(delrate));
		
        scanf("%d %d %d" , &N, &K, &M);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &rate[i]);
            sum += (ll)rate[i];
            if(rate[i] < 0)
            {
                negrate.push_back(make_pair(rate[i], i));
            }
        }
        for (int i = 0; i < M; ++i)
        {
            scanf("%d %d %d", &a, &b, &p);
            a--;    b--;
            for (int j = a; j <= b; ++j)
            {
                delrate[j] = min(delrate[j], p);
            }
        }
		
//		for(int i = 0; i < N; i++)
//			cout<<i<<" : "<<delrate[i]<<endl;
			
        sort(negrate.begin(), negrate.end());
        for (int i = 0; i < negrate.size(); ++i)
        {
            if(delrate[negrate[i].second] <= K)
            {
                K -= delrate[negrate[i].second];
                sum -= negrate[i].first;
            }
            if(K <= 0)
                break;
        }

        printf("%lld\n", sum);
    }    
}
