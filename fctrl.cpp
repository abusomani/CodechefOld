#include<iostream>
#include<cmath>
using namespace std;
int main()
{int t,*A,i,m,fact,p;
cin>>t;
A= new int[t];
for(i=0;i<t;i++)
 cin>>A[i];
for(i=0;i<t;i++)
{fact=0;
 p=1;m=1;
 while(m!=0)
 {m=A[i]/pow(5,p);
  fact+=m;
  p++;
 }
 cout<<fact<<endl;
 
}
return 0;
} 
