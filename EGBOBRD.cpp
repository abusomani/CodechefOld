#include <bits/stdc++.h>
#define M 100005
using namespace std;
typedef long long ll;

int main()
{
    int tests;
    scanf("%d" , &tests);

    int N, num[M];
    ll max_capacity;
    for(int t = 0; t < tests; t++)
    {
        scanf("%d %lld" , &N, &max_capacity);
        for (int i = 0; i < N; ++i)
        {
            scanf("%d" , &num[i]);
        }
        ll ans = 0;
        ll res = 0;
        for (int i = 0; i < N; ++i)
        {
            if(res >= num[i])
            {
                res -= num[i];
                if(res != 0)
                    res--;
            }
            else
            {
                num[i] = num[i] - res;
                ans += (ll)ceil((double)num[i] / max_capacity);
                res = max_capacity - num[i] % max_capacity;
                if(res == max_capacity)     res = 0;
                else                        res--;
            }
        }
        printf("%lld\n", ans);
    }    
}
