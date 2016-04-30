#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<cstring> 
using namespace std;
#define getcx getchar_unlocked
using namespace std;
/*inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}*/
void poweroftwo(long long k,long long &low,long long &high)
{low=1,high=2;
	for(int i=1;;i++)
		{if(k>=low&&k<high)
			return;
		else
			{low*=2;
			high*=2;
			}
		}
}
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{double x,l=3,sum=0;long long i,j,k;
	scanf("%lf %lld",&x,&k);
	poweroftwo(k,i,j);
	sum=((1+(k-i)*2)*x)/j;
	cout.setf(ios::fixed, ios::floatfield);
	cout<<setprecision(15)<<sum<<endl;
	}
return 0;
}
