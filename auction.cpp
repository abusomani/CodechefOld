#include<bits/stdc++.h>
using namespace std;
#define modulus 1000000007
long long modpow(int base,int exp) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main()
{int t;
cin>>t;
while(t--)
	{int n;
	cin>>n;
	int x=n/3,y=n%3;
	if(n==1)
	cout<<"1"<<endl;

	else
	{
	 if(y==1)
		{long long ans=modpow(3,x-1)*4%modulus;
		cout<<ans<<endl;
		}
	else if(y==2)
		{long long ans=modpow(3,x)*2%modulus;
		cout<<ans<<endl;
		}
	else
		{long long ans=modpow(3,x);
		cout<<ans<<endl;
		}
	}
	}
	return 0;
}
