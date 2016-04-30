#include<stdio.h>
#define scanint(x)  scanf("%lld",&x)
#define py printf("YES\n")
#define pn printf("NO\n")
int main()
{
	long long t,x,y;
	scanint(t);
	while(t--)
	{
		scanint(x);     scanint(y);
		if(x==0 && ( y==0 )) 
	    { py;  continue;  }      

		if(x==0)
		{
			if(y<0)			y = -y;
			if(y%2 == 0)	py;			
			else			pn;	
			continue;	
		}
		
		if(x>0 && x%2==1 && ( y>=(-x)+1 && y<=x+1))
		{  py;  continue;  }
		if(x<0 && (-x)%2==0 && ( y>=x && y<=(-x) ))
		{  py; continue;  }
		
		if(y%2==0  ||  (-y)%2==0)
		{
		if(y>0 && ( x>=(-y) && x<=y-1 ))
		{  py; continue;  }
		if(y<0 && ( x>=y && x<=(-y)+1 ))
		{  py;  continue;  }
		}
		pn;
	}
}
