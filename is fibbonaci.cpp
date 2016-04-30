#include<iostream>
#include<string.h>
using namespace std;
unsigned long long int fib[5500];
void make() {
    int i=2;
    fib[0]=0;
    fib[1]=1;
    while(i<5500) {
        fib[i]=fib[i-1]+fib[i-2];
        i++;
    }
}
void conv(char *s) {
    int l=strlen(s)-1, res=0;
    unsigned long long int val=0,temp=1;
    while (l>=0) {
        val = val+(s[l]-'0')*temp;
        temp*=10;
        l--;
    }
    l=0;
     for (l=0;l<5500;l++) {
            if (fib[l] == val) {
                cout<<"YES\n";
                res=1;
                break;
            }
        }
        if (res==0) {
            cout<<"NO\n";
        }
}
main() {
 
    make();
    int t,res=0,i;
    char s[1001];
    cin>>t;
    while (t--) {
        cin>>s;
        conv(s);
    }
}
