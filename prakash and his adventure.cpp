#include<bits/stdc++.h>
using namespace std;
double squareroot(double x) {
    if (x <= 0)
        return 0;       // if negative number throw an exception?
    int exp = 0;
    x = frexp(x, &exp); // extract binary exponent from x
    if (exp & 1) {      // we want exponent to be even
        exp--;
        x *= 2;
    }
    double y = (1+x)/2; // first approximation
    double z = 0;
    while (y != z) {    // yes, we CAN compare doubles here!
        z = y;
        y = (y + x/y) / 2;
    }
    return ldexp(y, exp/2); // multiply answer by 2^(exp/2)
}
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int w,d,s,r;
		cin>>w>>d>>s>>r;
		double ans;
		if(s==r)
			{
				ans=squareroot(w*w+d*d)/s;
				cout<<"0 "<<std::fixed<<std::setprecision(8)<<ans<<endl;
			}
		else
			{
				double x=(double)(s*w)/squareroot(abs(r*r-s*s));
				ans=(squareroot(w*w+x*x)/s)+(d-x)/r;
				cout<<d-x<<" "<<std::fixed<<std::setprecision(8)<<ans<<endl;
			}
		
	}
	return 0;
}
