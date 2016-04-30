#include <bits/stdc++.h>
#define M 1005
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll arr[M][M];
ll sum[M];

void Pascal()
{
	memset(sum , 0, sizeof(sum));
    for (int line = 0; line < M; line++)
    {
        for (int i = 0; i <= line; i++)
        {
            if (line == i || i == 0)
            {
                arr[line][i] = 1;
                sum[line] += 1;
                sum[line] %= MOD;
            }
            else
            {
                arr[line][i] = (arr[line-1][i-1] + arr[line-1][i]) % MOD;
                sum[line] += arr[line][i];
                sum[line] %= MOD;
            }
        }
    }
}

ll power(ll base, ll exponent, ll modulus)
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

int main()
{
    int Cases;
    scanf("%d" , &Cases);

    Pascal();
    int N, i, j, r, Q;
    while(Cases--)
    {
        scanf("%d %d" , &i, &j);
        i--;	j--;
        ll val = arr[i][j];
        scanf("%d", &Q);
        while(Q--)
        {
            scanf("%d", &r);
            r--;
            if(r < i)
                printf("%lld\n", sum[r]);
            else
            {
            	ll tmp2 = power(2, (r - i), MOD);
            	ll tmp = sum[r] - ((val * tmp2) % MOD);
            	if(tmp < 0)
            		tmp += MOD;
            	printf("%lld\n", tmp);
            }               
        }
    }    
}
