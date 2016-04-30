#include<iostream>
using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main()
{int base,mod;
int t;
cin>>t;
while(t--)
{cin>>base>>mod;//6n^5 + 15n^4 + 10n^3 - n) / 30 
long ans=((6*modpow(base,5,mod)+15*modpow(base,4,mod)+10*modpow(base,3,mod)-modpow(base,1,mod))/30)%mod;
cout<<ans;
}
return 0;
}
