#include <bits/stdc++.h>
#define MOD 1000000007
#define getchar getchar_unlocked
using namespace std;
 
int arr[10000010];
inline int scan()
{
    int n=0;
    char ch=getchar();
    while(ch<'0' || ch>'9') ch=getchar();
    while(ch>='0' && ch<='9')
    {
        n=(n<<3)+(n<<1)+ch-'0';
        ch=getchar();
    }
    return n;
}
int mypow( int base,int exp)
{
   int result=1;
    while(exp>0)
    {
        if(exp&1)
            result=(result*base)%MOD;
        exp=exp>>1;
        base=(base*base)%MOD;
    }
    return result;
}
int main()
{
    int t,N,M,L,R,prev,A[10000010],B[10000010];
    t=scan();
    while(t--)
    {
        N=scan();
        M=scan();
        L=scan();
        R=scan();
    int answer = 0;
	int last = -1;
	int power;
	for(int d = M; d >= 1; --d)
	{
	    int div = M / d;
	    if(div != last)
	    {
	        power = mypow(div, N);
	        last = div;
	    }
	    A[d] = power;
	    int S = 0;
	    int k = 2 * d;
	    while(k <= M)
	    {
	        S += B[k];
	        if(S >= MOD) S %= MOD;
	        k += d;
	    }
	    B[d] = A[d] - S;
	    if(B[d] < 0) B[d] += MOD;
	    if(B[d] >= MOD) B[d] %= MOD;
	    if(d >= L && d <= R) 
	    {
	        answer += B[d];
	        if(answer >= MOD) answer %= MOD;
	    }
	}
	cout << answer << endl;
    }
    return 0;
}
