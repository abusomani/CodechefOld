#include<bits/stdc++.h>
using namespace std;
void getv(int *p)
{
 *p=0;
  int ch=getchar_unlocked();
 while(ch<'0' && ch>'9')
      ch=getchar_unlocked();
 while(ch>='0' && ch<='9')
      {
        *p=(*p<<3)+(*p<<1)+ch-48;
         ch=getchar_unlocked();
      }
}
  #define pc(x) putchar_unlocked(x);
    inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }
int main()
{int t;
getv(&t);
while(t--)
	{int n,x,sum=0,count=0;
	getv(&n);
	for(int i=0;i<n;i++)
		{getv(&x);
		if(x!=0)
		count++;
		sum+=x;
		}
	if(sum==100)
	printf("YES\n");
	else if(sum<100)
	printf("NO\n");
	else
		{x=sum-100;
		if(x<count)
		printf("YES\n");
		else
		printf("NO\n");
		}
	}
	return 0;
}
