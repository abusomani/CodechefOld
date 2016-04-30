#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

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
long long pow(int a, int b,int MOD)
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
 
long long InverseEuler(int n,int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long factMOD(int n, int MOD)
{
    long long res = 1; 
    while (n > 0)
    {
        for (int i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0) 
            res = MOD - res;
    }
    return res;
}
 
long long C(int n, int r, int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) * 
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}
int main()
{int n;
int MOD=pow(10,9)+7;
cin>>n;
if(n>=13)
{ if(n%2==0)
	{n=(n/2)-1;
	n=C(n,6,MOD);
	cout<<n;
	}
	else
	{n=(n+1)/2-1;
	n=C(n,6,MOD);
	cout<<n;
	}
}
else
cout<<"0";
return 0;
}
