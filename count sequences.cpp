#include<stdio.h>
#define M 1000003
#define ll long long
//ll int fact[1000003],invf[1000003];
ll int x,y;
void ee(int a,int b)
{
    ll int tmp;
    if(a%b==0)
    {
        x=0;
        y=1;
        return ;
    }
    ee(b,a%b);
    tmp=x;
    x=y;
    y=tmp-y*(a/b);
}
ll int inverse(int a)
{
    ee(a,M);
    if(x<0)
        x+=M;
    return x;
}
int countFact(int n, int p)
{
    int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
long long int pow(int a, int b, int MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
long long factMOD(int n, int MOD)
{
    long long res = 1;
    int i,m;
    while (n > 0)
    {
        for (i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}
long long int C(int n, int r, int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}
int main()
{
    int i,t;
    ll int ans,n,l,r,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&l,&r);
        r=r-l+1;
        num=n+r;
        ans=C(num,r,M)-1;
        if(ans<0)
            ans+=M;
        printf("%lld\n",ans);
    }
    return 0;
}