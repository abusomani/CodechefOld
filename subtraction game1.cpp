#include<stdio.h>
#define gc getchar_unlocked
inline int getn(){
	int n=0, c=gc();
	while(c < '0' || c > '9') c = gc();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = gc();
	return n;
}
 
long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int t,n,i;
    long long n1,n2;
    t=getn();
    while(t--)
    {
 
        n=getn();
        n1=getn();
        if(n>1)
        {
            for(i=1;i<n;i++)
            {
                n2=getn();
                n1=gcd(n2,n1);
            }
        }
        printf("%lld\n",n1);
    }
    return 0;
}
