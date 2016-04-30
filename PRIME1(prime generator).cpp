  //           Sieve of Eratosthenes
#include<iostream>
#include<math.h>
#include<list>
using namespace std;
int main()
{
	 int i,k=2,cases;
	 long m,n;
     int t=32000;
     list<int> l;
     for(i=2;i<=t;i++)
     l.push_back(i);
     list<int>:: iterator p,p1,p2;
     p=l.begin();
     p++;
     p2=p;
     while(1)
     {
         p=p2;
		 while(p!=l.end())	
		 {
		 	if((*p)%k==0)
		 	{
		 		p1=p;
		 		p++;
		 		l.erase(p1);
		 	}
		 	else
		 	p++;
		 }
		 k=*p2;
		 p2++;
		 if(*p2>=sqrt(t))   break;	 
     }
	cin>>cases;
    while(cases--)
    {
    	cin>>m>>n;
    	if(m==1) m++;
    	list<int> l2;
    	for(i=m;i<=n;i++)
    	l2.push_back(i);
    	p=l.begin();
    	while(1)
        {
         k=*p;
        p++;
         p2=l2.begin();
		 while(p2!=l2.end())	
		 {
		 	if((*p2)%k==0  &&  (*p2)/k !=1 )
		 	{
		 		p1=p2;
		 		p2++;
		 		l2.erase(p1);
		 	}
		 	else
		 	p2++;
		 }
		
		 if(*p>sqrt(n))   break;	 
        }
        p2=l2.begin();
		 while(p2!=l2.end())	
		 {   cout<<*p2<<endl;   p2++;  }
    }
}
