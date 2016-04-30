#include <cstdio>
#define gc getchar_unlocked
 
void scanint(long long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
 
int main()
{
	long long n,m,q;
	scanint(n);
	scanint(m);
	while(m--)
	{
		scanint(q);
		if(q<(n+2) || q>3*n)
			printf("0\n");
		else if (q<(2*n+1))
			printf("%lld\n",n - (2*n+1-q));
		else if (q>(2*n+1))
			printf("%lld\n",3*n-q+1);
		else
			printf("%lld\n",n);
	}
	return 0;
} 
