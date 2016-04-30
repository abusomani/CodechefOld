#include<iostream>
#include<math.h>
using namespace std;
int main()
{int t,sum=0,c,sum1=0,sum2=0;
cin>>t;
while(t--)
	{int x,y;
	cin>>x>>y;
	sum1+=x;
	sum2+=y;
	if(fabs(sum1-sum2)>sum)
		if(x-y>0)
			{sum=fabs(sum1-sum2);
			c=1;
			}
		else
			{sum=fabs(sum1-sum2);
			c=2;
			}
	}
cout<<c<<" "<<sum;
return 0;
}
