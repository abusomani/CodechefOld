#include<bits/stdc++.h>
using namespace std;
double calc_root(double a,double b,double c)
{
	double d=(b*b)-(4*a*c);
	if(d==0)
		return -b/(2*a);
	if(d>0)
		return (-b-sqrt(d))/(2*a);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double p,s;
		cin>>p>>s;
		double x,y,z;
		x=calc_root(6,-p,s);
		y=x;
		z=(p-(8*x))/4;
		double vol=x*y*z;
		printf("%.2lf\n",vol);
	}
	return 0;
}
