#include<stdio.h>
#include<cstring>
#define s(x) scanf("%d",&x)
#define p(x) printf("%d",x)
#define nl   printf("\n")
typedef long long ll;
ll factorial[20];
void preProcess()
{
   factorial[0] = 1;
   for(int i = 1; i <= 20; i++)
   factorial[i] = i * factorial[i - 1];
}
int main()
{
	preProcess();
	int i,j,t,l,d;
	char num[20];
	short c;
	ll ans;
	s(t);
	while(t--)
	{
		int f[10]={0};
		ans=0;
		ll d=1;
		scanf("%s",num);
		l=strlen(num);
		for(i=l-1;i>=0;i--)
		{
			c=num[i]-'0';
			f[c]++;
			d=d*f[c];
			for(j=0;j<c;j++)
			{
				ans+=(f[j]*factorial[l-i-1])/d;
			}
		}
		p(ans+1);  nl;
	}
	return 0;
}
