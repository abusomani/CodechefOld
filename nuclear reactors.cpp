#include<bits/stdc++.h>
using namespace std;
#define s(n)                        scanf("%d",&n)
#define p(n)                        printf("%d ",n)
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define first fr
#define second sd
#define it(t) t :: iterator it
#define rep(it,s) for(it=s.begin();it!=s.end();it++)
 
 
#define ll long long int
int main()
{ios_base::sync_with_stdio(false);
     int a,n,k,out;
     s(a);s(n);s(k);
     int j=0,i=0;
     int *S=new int[k];
 
     forall(i,0,k)
     {
          out=a%(n+1);
          p(out);
          a=a/(n+1);
     }
     cout<<endl;
 
}
