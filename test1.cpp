#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include<math.h>
using namespace std;
const unsigned long long int md = 1000003; 
const unsigned long long int co = md+2;
unsigned long long int ft[co];

unsigned long long int fact(unsigned long long int n)
{   
    return ft[n];
}

void fct(){
    ft[0]=1;
    for(unsigned long long int i = 1;i<co;i++){
        ft[i]=(i*ft[i-1]) % md;
    }
}

unsigned long long int pow(unsigned long long int x, unsigned long long int n, unsigned long long int mod){
    unsigned long long int result=1; 
    x = x % md;
    while(n>0){
        if(n%2 ==1){
            result = (result*x) % md;
        }
        n= n>>1;
        x= (x*x)% md;   
    }
    return result;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    unsigned long long int l,r , n;
    unsigned long long int result;
    int T;
    fct();
    cin>>T;
    while(T--){
        cin>>n>>l>>r; 
        unsigned long long int mod = md-2,N=n%md,K=(r-l+1)%md;
		
        result = (fact((N+K)%md) * pow( ( fact(K) * fact(N) ) , mod, md )) %md ;
        cout<<result-1<<endl; 
    }

    return 0;
}
