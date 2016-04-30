#include<iostream>
using namespace std;
long long maxz(long long ,long long );
long  long f(unsigned long long );
long long aray[1000000]={0};
int main()
{
    
    long long i;
    int nom =10;
    while(nom--)
    {
    cin>>i;
    if(cin.eof())
    return 0;
    long long j=f(i/2);
    long long k=f(i/3);
    long long l=f(i/4);
    cout<<maxz(j+k+l,i)<<endl;
    i=0;
    }
}
long long maxz(long long a,long long b)
{
    if(a>b)
    return a;
     return b;
}
long long f(unsigned long long i)
{
    if (i<1000000)
    {
        if(aray[i]!=0)
        return aray[i];
    }    
    if(i==0)
        return 0;
        long long r= maxz (   f(i/2)+f(i/3)+f(i/4)  ,  i );    
    if(i<1000000)
    aray[i]=r;    
       return r;
}   
