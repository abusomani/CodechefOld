/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL res[1000001], one[1000001];
inline bool scan_d(int &ret) {
        char c; int sgn;
        if(c=getchar(),c==EOF) return 0;
        while(c!='-'&&(c<'0'||c>'9')) c=getchar();
        sgn=(c=='-')?-1:1;
        ret=(c=='-')?0:(c-'0');
        while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
        ret*=sgn;
        return 1;
}
int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
//    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b;
    int c,d = 0,e,f = 0,g,h = 0,x,y,z;
    res[1] = one[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        a = (LL)i*(LL)(i - 1) / 2ll;
        one[i] = a - one[i];
        res[i] += (one[i] + 1);
        for(int j = 2; j <= 1000000/i; j++){
            one[j*i] += one[i]*j;
            res[j*i] += one[i];
        }
    }
    c = 300000; b = 0;
    while(c--){
        d = 1000000;
        b += res[d]*(LL)d;
    }
    cout << b << endl;
}

