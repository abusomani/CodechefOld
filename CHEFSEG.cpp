#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll pow(ll base, int exponent)
{
    int result = 1;
    while (exponent > 0)
    {
        if (exponent%2 == 1)
           result = (result * base);
        exponent = exponent >> 1;
        base = (base * base);
    }
    return result;
}
int main()
{
	int t,pow2;
	ll k,l,two;
	long double ans;
	cin>>t;
	while(t--)
	{
		cin>>l>>k;
		pow2 =	log2(k);	
		two = pow(2,pow2);
		k = k- two + 1;
	//	cout<<two<<"  "<<k<<endl;
		ans = (long double)(2*k-1)*(l)/(2*two);
		cout<<std::setprecision(16)<<ans<<endl;
	//printf("%lf\n",ans);
	}
}
